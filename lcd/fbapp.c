#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/mman.h>

//#define LOG printf("[%s]-[%d]",__func__,__LINE__);printf;
#define LOG printf;


#define DEVICENAME "/dev/fb0"

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned short u16;

void draw_back(u32 width,u32 height,u16 color);

u16 *pfb=NULL;
int main()
{
	int res=-1,fd;
	struct fb_var_screeninfo vinfo={0};
	struct fb_fix_screeninfo finfo={0};
	fd=open(DEVICENAME,O_RDWR);
	if(fd==-1){
		perror("open");
		return -1;
	}
	printf("device %s open success.\n",DEVICENAME);
	//获取虚拟信息
	res=ioctl(fd,FBIOGET_VSCREENINFO,&vinfo);    
	if(res==-1){
		perror("ioctl");
		close(fd);
		return -1;
	}
	printf("xres=%u,yres=%u,xres_virtual=%u,yres_virtual=%u,bits_per_pixel=%ld\n",vinfo.xres,vinfo.yres,vinfo.xres_virtual,vinfo.yres_virtual,vinfo.bits_per_pixel);
	//获取屏幕固定信息
	res=ioctl(fd,FBIOGET_FSCREENINFO,&finfo);
	if(res==-1){
		perror("ioctl");
		close(fd);
		return -1;
	}
	printf("smem_start=0x%x,smem_len=%ld\n",finfo.smem_start,finfo.smem_len);
	//地址映射 mmap
	pfb=mmap(NULL,finfo.smem_len,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
	if(pfb==NULL){
		perror("mmap");
		return -1;
	}
	printf("*pfb=%p\n",pfb);
	draw_back(vinfo.xres,vinfo.yres,0xf00f);
	munmap(pfb,finfo.smem_len);
	close(fd);
	
}


void draw_back(u32 width,u32 height,u16 color)
{
	u32 x,y;
	for(y=0;y<height;y++){
		for(x=0;x<width;x++){
			*(pfb+y*width+x)=color;
		}
	}
}

























