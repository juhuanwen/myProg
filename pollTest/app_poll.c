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
       ret=poll(&pollfd1,1,3000) ;           //һ��poll, ��ʱ5000ms,��������״̬
	   //printf(" ret=%d\n",ret);
       if(ret==0){                        //��ʱ
          printf("time out\n");
       }
       else if(ret>0){                   //poll���Ʊ����ѣ���ʾ�����ݿɶ�
        //read(fd,buf,6);
		printf(" the data is %s \n\n",buf);
       }
 	}
	close(fd);
}

