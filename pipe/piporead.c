#include <stdio.h>
#include <unistd.h>
#include <fcntl.h> 
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#define FIFO_NAME "/tmp/fifo"
int main()
{
    int fd = 0;
    int ret = 0;
    char buffer[1024] = {0};

    unlink(FIFO_NAME);
    ret = mkfifo(FIFO_NAME,0777);
    if(ret != 0)
    {
        printf("mkfifo err!\n");
        return -1;
    }


    printf("mkfifo success,open O_RDONLY!\n");

    fd = open(FIFO_NAME,O_RDONLY);
    printf("zusissiiii\n");
    if(fd < 0)
    {
        printf("open FIFO_NAME fail!\n");
        return -1;
    }
    else
    {
        while(1)
        {
            ret = read(fd,buffer,sizeof(buffer));
            if(-1 == ret )
            {
                printf("write buffer fail!\n");
                return -1;
            }
            printf("FIFO read buffer:%s\n",buffer);
            memset(buffer,0,sizeof(buffer));
            sleep(1);
        }

    }

    close(fd);
    return 0;
}
