#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <linux/videodev2.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/mman.h>
#include <poll.h>

#include "libjpeg/jpeglib.h"
#include "libjpeg/jerror.h"
#include "v4l2.h"

#define VIDEO_COUNT       4
#define IMAGE_WIDTH     640
#define IMAGE_HEIGHT    480
#define IMAGE_FILE_DIR  "/tmp/LCDProj/out.bmp"


#pragma pack(1)
typedef struct bit_map_file_header_type
{
    unsigned short bfType;      /// 位图文件的类型,
    unsigned long  bfSize;      /// 位图文件的大小，以字节为单位
    unsigned short bfReserved1; /// 位图文件保留字，必须为0
    unsigned short bfReserved2; /// 同上
    unsigned long  bfOffBits;   /// 位图阵列的起始位置，以相对于位图文件   或者说是头的偏移量表示，以字节为单位

    unsigned long  biSize;         /// 位图信息头的长度，以字节为单位
    unsigned long  biWidth;        /// 位图的宽度，以像素为单位
    unsigned long  biHeight;       /// 位图的高度，以像素为单位
    unsigned short biPlanes;       /// 目标设备的级别,必须为1
    unsigned short biBitCount;     /// 每个像素所需的位数，必须是1(单色),4(16色),8(256色)或24(2^24色)之一
    unsigned long  biCompression;  /// 位图的压缩类型，必须是0-不压缩，1-BI_RLE8压缩类型或2-BI_RLE4压缩类型之一
    unsigned long  biSizeImage;    /// 位图大小，以字节为单位
    unsigned long  biXPelsPerMeter;/// 位图目标设备水平分辨率，以每米像素数为单位
    unsigned long  biYPelsPerMeter;/// 位图目标设备垂直分辨率，以每米像素数为单位
    unsigned long  biClrUsed;      /// 位图实际使用的颜色表中的颜色变址数
    unsigned long  biClrImportant; /// 位图显示过程中被认为重要颜色的变址数
} BIT_MAP_FILE_HEADER_TYPE;

typedef struct video_buffer_type{
    void  *start;
    size_t length;
} VIDEO_BUFFER_TYPE;
#pragma pack()

static char camera_name[32] = {0};
static int camera_connect_status = -1;
static int camera_connect_status1 = -1;
static int camera_fd = 0;

static VIDEO_BUFFER_TYPE framebuf[VIDEO_COUNT];
static char *pcamera_buff = NULL;

struct jpeg_decompress_struct cinfo;
struct jpeg_error_mgr jerr;

/// 获取摄像头设备文件
int Get_Camera_dev_name(char *name, int len)
{
    int ret = -1;
    FILE *camera_fp = NULL;
    char tmpBuff[32] = {0};
    int video_num = 0;

    do
    {
        camera_fp = popen("ls /dev | grep video", "r");
        if(!camera_fp)
        {
            LOG("open video dev error!\n");
            break;
        }

        memset(name, 0, len);
        if ((!fgets(tmpBuff, 32, camera_fp))
         || !strstr(tmpBuff, "video"))
        {
            pclose(camera_fp);
            break;
        }
        pclose(camera_fp);

        video_num = atoi(&(tmpBuff[5]));
        sprintf((char *)name, "/dev/video%d", video_num);
        ret = 1;
    }
    while (0);

  return ret;
}

/// 检查摄像头连接状态
static int camera_status_check(char *name, int len)
{
    int ret = -1;
    struct stat camera_stat;

    if(!strstr(name, "/dev"))
    {
        Get_Camera_dev_name(name, len);
    }

    if(stat(name, &camera_stat) == -1)
    {
        Get_Camera_dev_name(name, len);
    }

    if(stat(name, &camera_stat) != -1)
    {
        LOG("Connect to camera!\n");
        ret = 1;
    }
    else
    {
        LOG("Can't connect to %s\n", name);
    }

    return ret;
}

/// 初始化摄像头
int camera_init_param(int width, int height)
{
    int ret = 0;
    struct v4l2_streamparm stream_param = {0};
    struct v4l2_format format = {0};
    struct v4l2_control ctrl = {0};
    struct v4l2_crop cropcap_old = {0};
    struct v4l2_crop cropcap = {0};
    struct v4l2_requestbuffers requestbuffers = {0};
    struct v4l2_buffer buf;
    int stream_type = 0;
    int i = 0;

    do
    {
        camera_connect_status1 = camera_status_check(camera_name, sizeof(camera_name));
        if(camera_connect_status1 < 0)
        {
            LOG("camera is not connect!\n");
            break;
        }

        /// 打开摄像头
        if(camera_fd > 0)
        {
            close(camera_fd);
            camera_fd = 0;
        }
        camera_fd = open(camera_name, O_RDWR | O_NONBLOCK, 0);
        if(camera_fd < 3)
        {
            LOG("open camera error!\n");
            break;
        }

        /// 设置参数
        stream_param.type                                = V4L2_BUF_TYPE_VIDEO_CAPTURE;
        stream_param.parm.capture.capability             = 30;
        stream_param.parm.capture.capturemode            = V4L2_MODE_HIGHQUALITY;
        ret = ioctl(camera_fd, VIDIOC_S_PARM, &stream_param);
        if(ret < 0)
        {
            LOG("Set parameter faied, errno is %d!\n", errno);
            break;
        }

        /// 设置数据格式
        format.type                = V4L2_BUF_TYPE_VIDEO_CAPTURE;
        format.fmt.pix.width       = width;
        format.fmt.pix.height      = height;
        format.fmt.pix.pixelformat = V4L2_PIX_FMT_MJPEG; //V4L2_PIX_FMT_YUYV;
        format.fmt.pix.field       = V4L2_FIELD_ANY;
        ret = ioctl(camera_fd, VIDIOC_S_FMT, &format);
        if(ret < 0)
        {
            LOG("can not set format, errno is %d!\n", errno);
            break;
        }

        /// 获取裁剪参数
        cropcap_old.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
        ret = ioctl(camera_fd, VIDIOC_G_CROP, &cropcap_old);
        if(!ret)
        {
            LOG("not support cropping!\n");
            break;
        }

        /// 设置裁剪参数
        cropcap.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
        cropcap.c.left   = cropcap_old.c.left;
        cropcap.c.top    = cropcap_old.c.top;
        cropcap.c.width  = cropcap_old.c.width;
        cropcap.c.height = cropcap_old.c.height;
        ret = ioctl(camera_fd, VIDIOC_S_CROP, &cropcap);
        if((1 == ret) && (22 == errno))
        {
            LOG("not support cropping!\n");
            break;
        }

        /// 获取白平衡
        ctrl.id = V4L2_CID_BRIGHTNESS;
        ret = ioctl(camera_fd, VIDIOC_G_CTRL, &ctrl);
        if(ret < 0)
        {
            LOG("set V4L2_CID_AUTO_WHITE_BALANCE error, errno is %d!\n", errno);
            break;
        }

        /// 分配内存
        requestbuffers.count  = VIDEO_COUNT;
        requestbuffers.type   = V4L2_BUF_TYPE_VIDEO_CAPTURE;
        requestbuffers.memory = V4L2_MEMORY_MMAP;

        ret = ioctl(camera_fd, VIDIOC_REQBUFS, &requestbuffers);
        if(ret < 0)
        {
            LOG("video0 does not support memory mapping, errno is %d!\n", errno);
            break;
        }

        if(requestbuffers.count < 2)
        {
            LOG("Insufficient buffer memory on video0!\n");
            break;
        }

        for(i=0; i<requestbuffers.count; i++)
        {
            memset(&buf, 0, sizeof(buf));
            buf.index  = i;
            buf.type   = V4L2_BUF_TYPE_VIDEO_CAPTURE;
            buf.memory = V4L2_MEMORY_MMAP;
            ret = ioctl(camera_fd, VIDIOC_QUERYBUF, &buf);
            if(ret < 0)
            {
                LOG("can not request buffers\n");
                ret = -2;
                break;
            }

            framebuf[i].length = buf.length;
            framebuf[i].start = mmap(NULL, buf.length, PROT_READ|PROT_WRITE, MAP_SHARED, camera_fd, buf.m.offset);
            if(framebuf[i].start == MAP_FAILED)
            {
                LOG("can not mmap buffer, errno is %d!\n", errno);
                ret = -3;
                break;
            }
            memset(framebuf[i].start, 0, framebuf[i].length);
            LOG("start:%x  length:%d\n", (unsigned int)framebuf[i].start, framebuf[i].length);
        }

        if(ret < -1)
        {
            ret = -1;
            break;
        }

        for(i=0; i<requestbuffers.count; i++)
        {
            memset(&buf, 0, sizeof(buf));
            buf.index  = i;
            buf.type   = V4L2_BUF_TYPE_VIDEO_CAPTURE;
            buf.memory = V4L2_MEMORY_MMAP;
            ret = ioctl(camera_fd, VIDIOC_QBUF, &buf);
            if(ret < 0)
            {
                LOG("can not get data buffer\n");
                ret = -2;
                break;
            }
        }

        if(ret < -1)
        {
            ret = -1;
            break;
        }

        stream_type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
        ret = ioctl(camera_fd, VIDIOC_STREAMON, &stream_type);

        if(ret < 0)
        {
            LOG("Stream can not start!\n");
            ret = -2;
            break;
        }

        ret = 1;
    }
    while (0);

    return ret;
}

BIT_MAP_FILE_HEADER_TYPE bfh;

static void create_bmp_header(int width, int height)
{
    bfh.bfType          = (unsigned short)0x4D42;
    bfh.bfSize          = (unsigned long)(14 + 40 + width * height * 3);
    bfh.bfReserved1     = 0;
    bfh.bfReserved2     = 0;
    bfh.bfOffBits       = (unsigned long)(14 + 40);

    bfh.biSize          = 40;
    bfh.biWidth         = width;
    bfh.biHeight        = height;
    bfh.biPlanes        = 1;
    bfh.biBitCount      = 24;
    bfh.biCompression   = 0;
    bfh.biSizeImage     = width * height;
    bfh.biXPelsPerMeter = 0x00000B12;
    bfh.biYPelsPerMeter = 0x00000B12;
    bfh.biClrUsed       = 0;
    bfh.biClrImportant  = 0;
}

int read_Frame(void)
{
    struct pollfd pollfd;
    int ret = -1;
    struct v4l2_buffer buf;

    for(;;)
    {
        memset(&pollfd, 0, sizeof(pollfd));
        pollfd.fd = camera_fd;
        pollfd.events = POLLIN;
        ret = poll(&pollfd, 1, 1500);
        if(-1 == ret)
        {
            LOG("VIDIOC_QBUF fail.\n");
            break;
        }
        else if(0 == ret)
        {
            LOG("poll time out\n");
			ret = -1;
            continue;
        }

        if(pollfd.revents & POLLIN)
        {
            LOG("VIDIOC_DQBUF starting\n");
            memset(&buf, 0, sizeof(buf));
            buf.type   = V4L2_BUF_TYPE_VIDEO_CAPTURE;
            buf.memory = V4L2_MEMORY_MMAP;
            ret = ioctl(camera_fd, VIDIOC_DQBUF, &buf);
            if(ret != 0)
            {
                LOG("VIDIOC_QBUF fail.\n");
            }
            break;
        }
    }

    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_decompress(&cinfo);

    jpeg_mem_src(&cinfo, framebuf[0].start, buf.length);
    jpeg_read_header(&cinfo, TRUE);
    /// 分配内存存储字节
    pcamera_buff = (char*)calloc(cinfo.image_width*cinfo.image_height*cinfo.num_components, 1);

    /// 开始解压
    jpeg_start_decompress(&cinfo);
    JSAMPROW row_pointer[1];

    while (cinfo.output_scanline < cinfo.output_height)
    {
        row_pointer[0] = &pcamera_buff[(cinfo.output_scanline)*cinfo.image_width*cinfo.num_components];
        jpeg_read_scanlines(&cinfo,row_pointer ,1);
    }

    unlink(IMAGE_FILE_DIR);
    sync();
    create_bmp_header(IMAGE_WIDTH, IMAGE_HEIGHT);
    FILE *file = fopen(IMAGE_FILE_DIR, "wb");
    fwrite(&bfh, sizeof(BIT_MAP_FILE_HEADER_TYPE), 1, file);
    fwrite(pcamera_buff, cinfo.image_width*cinfo.image_height*cinfo.num_components, 1, file);
    fclose(file);
	free(pcamera_buff);
    /////////////结束解压
    jpeg_finish_decompress(&cinfo);
    /// jpeg_destroy_decompress(&cinfo);

    /// 放回队列
    ret = ioctl(camera_fd, VIDIOC_QBUF, &buf);

    return ret;
}

void closeCamera(void)
{
    int ret = -1;
    int i = 0;
    enum v4l2_buf_type type;

    do
    {
        type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
        ret = ioctl(camera_fd, VIDIOC_STREAMOFF, &type);
        if(0 != ret)
        {
            perror("VIDIOC_QBUF fail.\n");
            break;
        }

        for(i=0; i<VIDEO_COUNT; i++)
        {
            munmap(framebuf[i].start, framebuf[i].length);
        }
        close(camera_fd);
    }
    while (0);
}


int main(void)
{
    Get_Camera_dev_name(camera_name, sizeof(camera_name));
    camera_init_param(IMAGE_WIDTH, IMAGE_HEIGHT);
    read_Frame();
    closeCamera();

    return 0;
}

