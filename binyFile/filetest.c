
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef unsigned char u8;
#define DEBUG
#ifdef DEBUG
	#define LOG printf("%s|%4d|",__FILE__,__LINE__);printf
#else
	#define LOG printf;
#endif
/*************************************
更改文件中前4个字节，并将地址中的所有末尾写入
文件名，要更改的前四个字节的数值，要新添加了数据指针，要添加的数据字节数
*************************************/
void addByte2File(char * FILENAME,int num,u8 *buf,int size){
	int fd;
	int fd1;
	u8 buff[1024];
	char execbuf[100]={0};
	int i=0;
	sprintf(execbuf,"mv %s %s",FILENAME,"/tmp/bak");
	system(execbuf);//源文件删除
	fd=open(FILENAME,O_CREAT|O_RDWR|O_TRUNC);
	if(fd<0){
		LOG("open %s error\n",FILENAME);
		sprintf(execbuf,"mv bak %s",FILENAME);//把源文件弄回来
		system(execbuf);
		return;
	}
	fd1=open("/tmp/bak",O_RDONLY);
	if(fd1<0){
		LOG("open %s error\n","/tmp/bak");
		close(fd1);
		close(fd);
		return;
	}
	//前4个字节重新赋值
	lseek(fd,0,SEEK_SET);
	write(fd,&num,4);
	lseek(fd,0,SEEK_END);//指针放到最后，等待追加
	//将原来的有效数据读取出来追加
	lseek(fd1,4,SEEK_SET);
	while((i=read(fd1,buff,1024))>0){//读取源数据
		LOG("read bytes=%d\n",i);
		write(fd,buff,i);//追加
	}
	write(fd,buf,size);//追加一条
	close(fd1);
	close(fd);
	
}
int main()
{
	u8 buf[1000];
	u8 buf1[16];
	int i=0;
	int fd;
	for(i=0;i<1000;i++){
		buf[i]=i%256;
	}
	fd=open("tmp",O_CREAT|O_RDWR|O_TRUNC);
	if(fd<0){
		perror("open tmp error:\n");
	}
	write(fd,buf,1000);
	close(fd);
	for(i=0;i<16;i++){
		buf[i]=i+32;
	}
	addByte2File("tmp",12,buf,16);
	
}
