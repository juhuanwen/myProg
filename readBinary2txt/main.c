#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#define LOG printf("%s|%4d|",__func__,__LINE__);printf

//将一个二进制文件转化成一个文本文件并按照0x01,0x02这种格式输出
void readBinary2txt(char * FileName,char * desName)
{
	int i,j;
	int fd;
	int fdDes;
	int res;
	unsigned char ss[5];
	unsigned char buff[18432];
	//目标文件
	fdDes=open(desName,O_CREAT|O_TRUNC|O_RDWR);
	if(fdDes<0){
		LOG("open %s error\n",desName);
	}
	//源文件
	fd=open(FileName,O_RDONLY);
	if(fd<0){
		LOG("open %s error\n",FileName);
	}
	res=read(fd,buff,18432);
	LOG("read %d bytes from %s\n",res,FileName);
	for(i=0;i<res;i++){
		sprintf(ss,"0x%2x,",buff[i]);
		write(fdDes,ss,5);
		if(i%50==49){
			sprintf(ss,"\r\n");
			write(fdDes,ss,2);
		}
	}
	
	close(fd);
	close(fdDes);
}

int main()
{
	readBinary2txt("CompFile","123");
}