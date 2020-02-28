#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<poll.h>
 
//#define MSG printf("%s|%s|%d|",__FILE__,__func__,__LINE__);printf
#define MSG printf("%s|%04d|", __FILE__, __LINE__); printf

#define GPIO_NO_OPEN_DOOR     163              /// 开箱状态
//函数声明
static int gpio_export(int pin);
static int gpio_unexport(int pin);
static int gpio_direction(int pin, int dir);
static int gpio_write(int pin, int value);
static int gpio_read(int pin);
static int gpio_edge(int pin, int edge);
 
 
static int gpio_export(int pin)  
{  
    char buffer[64];  
    int len;  
    int fd;  
  
    fd = open("/sys/class/gpio/export", O_WRONLY);  
    if (fd < 0) 
    {  
        MSG("Failed to open export for writing!\n");  
        return(-1);  
    }  
  
    len = snprintf(buffer, sizeof(buffer), "%d", pin);  
    MSG("%s,%d,%d\n",buffer,sizeof(buffer),len);
    if (write(fd, buffer, len) < 0) 
    {  
        MSG("Failed to export gpio!");  
        return -1;  
    }  
     
    close(fd);  
    return 0;  
}  
static int gpio_unexport(int pin)  
{  
    char buffer[64];  
    int len;  
    int fd;  
  
    fd = open("/sys/class/gpio/unexport", O_WRONLY);  
    if (fd < 0) 
    {  
        MSG("Failed to open unexport for writing!\n");  
        return -1;  
    }  
  
    len = snprintf(buffer, sizeof(buffer), "%d", pin);  
    if (write(fd, buffer, len) < 0) 
    {  
        MSG("Failed to unexport gpio!");  
        return -1;  
    }  
     
    close(fd);  
    return 0;  
} 
//dir: 0-->IN, 1-->OUT
static int gpio_direction(int pin, int dir)  
{  
    static const char dir_str[] = "in\0out";  
    char path[64];  
    int fd;  
  
    snprintf(path, sizeof(path), "/sys/class/gpio/gpio%d/direction", pin);  
    fd = open(path, O_WRONLY);  
    if (fd < 0) 
    {  
        MSG("Failed to open gpio direction for writing!\n");  
        return -1;  
    }  
  
    if (write(fd, &dir_str[dir == 0 ? 0 : 3], dir == 0 ? 2 : 3) < 0) 
    {  
        MSG("Failed to set direction!\n");  
        return -1;  
    }  
  
    close(fd);  
    return 0;  
}  
//value: 0-->LOW, 1-->HIGH
static int gpio_write(int pin, int value)  
{  
    static const char values_str[] = "01";  
    char path[64];  
    int fd;  
  
    snprintf(path, sizeof(path), "/sys/class/gpio/gpio%d/value", pin);  
    fd = open(path, O_WRONLY);  
    if (fd < 0) 
    {  
        MSG("Failed to open gpio value for writing!\n");  
        return -1;  
    }  
  
    if (write(fd, &values_str[value == 0 ? 0 : 1], 1) < 0) 
    {  
        MSG("Failed to write value!\n");  
        return -1;  
    }  
  
    close(fd);  
    return 0;  
}
static int gpio_read(int pin)  
{  
    char path[64];  
    char value_str[3];  
    int fd;  
  
    snprintf(path, sizeof(path), "/sys/class/gpio/gpio%d/value", pin);  
    fd = open(path, O_RDONLY);  
    if (fd < 0) 
    {  
        MSG("Failed to open gpio value for reading!\n");  
        return -1;  
    }  
  
    if (read(fd, value_str, 3) < 0)
    {  
        MSG("Failed to read value!\n");  
        return -1;  
    }  
  
    close(fd);  
    return (atoi(value_str));
}  
// none表示引脚为输入，不是中断引脚
// rising表示引脚为中断输入，上升沿触发
// falling表示引脚为中断输入，下降沿触发
// both表示引脚为中断输入，边沿触发
// 0-->none, 1-->rising, 2-->falling, 3-->both
static int gpio_edge(int pin, int edge)
{
const char dir_str[] = "none\0rising\0falling\0both"; 
char ptr;
char path[64];  
    int fd; 
switch(edge)
{
    case 0:
        ptr = 0;
        break;
    case 1:
        ptr = 5;
        break;
    case 2:
        ptr = 12;
        break;
    case 3:
        ptr = 20;
        break;
    default:
        ptr = 0;
} 
  
    snprintf(path, sizeof(path), "/sys/class/gpio/gpio%d/edge", pin);  
    fd = open(path, O_WRONLY);  
    if (fd < 0) 
    {  
        MSG("Failed to open gpio edge for writing!\n");  
        return -1;  
    }  
  
    if (write(fd, &dir_str[ptr], strlen(&dir_str[ptr])) < 0) 
    {  
        MSG("Failed to set edge!\n");  
        return -1;  
    }  
  
    close(fd);  
    return 0;  
}
//GPIO1_17
int main()  
{  
    int gpio_fd, ret;
    struct pollfd fds[1];
    char buff[10];
    unsigned char cnt = 0;
 	int i=0;
    gpio_unexport(GPIO_NO_OPEN_DOOR);
 //   gpio_unexport(45);
 
    
//    //p8_12 init
//    gpio_export(44);
//    gpio_direction(44, 1);//output out
//    gpio_write(44, 1);
    
    //p8_11 init
    gpio_export(GPIO_NO_OPEN_DOOR);
    gpio_direction(GPIO_NO_OPEN_DOOR, 0);//input in
    gpio_edge(GPIO_NO_OPEN_DOOR,3);//边沿触发
	gpio_fd = open("/sys/class/gpio/gpio163/value",O_RDONLY);
	if( gpio_fd == -1 )
		MSG("gpio open");
	fds[0].fd = gpio_fd;
	fds[0].events  = POLLPRI;
	ret = read(gpio_fd,buff,10);
	if( ret == -1 )
		MSG("read");
	while(1){
		 ret = poll(fds,1,-1);
		 if( ret == -1 )
			 MSG("poll");
		   if( fds[0].revents & POLLPRI){
			   ret = lseek(gpio_fd,0,SEEK_SET);
			   if( ret == -1 )
				   MSG("lseek");
			   ret = read(gpio_fd,buff,10);
			   if( ret == -1 )
				   MSG("read");
				MSG("safdsf\n");
			   for(i=0;i<10;i++){
			   	MSG("buff[%d]=%2x\n",i,buff[i]);
			   	}
				/*此时表示已经监听到中断触发了，该干事了*/
				//...............
	
			}
	}
    return 0;
}

//记住使用poll()函数，设置事件监听类型为POLLPRI和POLLERR在poll()返回后，
//使用lseek()移动到文件开头读取新的值或者关闭它再重新打开读取新值。
//必须这样做否则poll函数会总是返回。



