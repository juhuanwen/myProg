#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define K2_NAME "/dev/K2"

typedef unsigned char u8;

int main()
{
	int fd;
	int i;
	u8 buf[8];
	fd=open(K2_NAME,O_RDWR);
	write(fd,buf,8);
	while(1){
	read(fd,buf,8);
	for(i=0;i<8;i++){
		printf("buf[%d]=%x\n",i,buf[i]);
	}
	}
	close(fd);
}
