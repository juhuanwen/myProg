#include <stdio.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <poll.h>


#define DEV_NAME "/dev/myPoll"

typedef unsigned char u8;
int main()
{
	int fd;
	int ret;
	struct pollfd pollfd1;
	char buf[1]={'0'};
	fd= open(DEV_NAME,O_RDWR);
	if(fd<0){
		perror("open fail\n");
	}
	memset(&pollfd1, 0, sizeof(pollfd1));
	pollfd1.fd=fd;
	pollfd1.events=POLLIN;
	 while(1){
       ret=poll(&pollfd1,1,3000) ;           //一个poll, 定时5000ms,进入休眠状态
	   //printf(" ret=%d\n",ret);
       if(ret==0){                        //超时
          printf("time out\n");
       }
       else if(ret>0){                   //poll机制被唤醒，表示有数据可读
        //read(fd,buf,6);
		printf(" the data is %s \n\n",buf);
       }
 	}
	close(fd);
}

