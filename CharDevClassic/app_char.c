#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define DEV_NAME "/dev/mychar"

int main()
{
	int fd;
	while(1){
		
		fd=open(DEV_NAME,O_RDWR);
		if(fd<0){
			perror("open device fail\n");
		}
		sleep(1);
		close(fd);
		sleep(1);
	}
}

