#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef union
{
	struct {
		unsigned char bit0	:1;
		unsigned char bit1	:1;
		unsigned char bit2	:1;
		unsigned char bit3	:1;
		unsigned char bit4	:1;
		unsigned char bit5	:1;
		unsigned char bit6	:1;
		unsigned char bit7	:1;
	}bitss;

}defbits;
defbits mytest;
#define R_1	mytest.bitss.bit0
#define R_2	mytest.bitss.bit1
#define R_3	mytest.bitss.bit2
#define R_4	mytest.bitss.bit3
#define R_5	mytest.bitss.bit4
#define R_6	mytest.bitss.bit5
#define R_7	mytest.bitss.bit6
#define R_8	mytest.bitss.bit7
int main()
{
	R_1=1;
	R_2=1;
	R_3=1;
	R_4=1;
	R_5=1;
	R_6=1;
	R_7=1;
	R_8=1;
	printf("mytest=%x\n",*(unsigned char*)(&mytest));

}