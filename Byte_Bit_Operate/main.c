#include <stdio.h>
#include <string.h>
#include <stdlib.h>

union{
	unsigned char flag10;
	struct{
		unsigned b0:1;
		unsigned b1:1;
		unsigned b2:1;
		unsigned b3:1;
		unsigned b4:1;
		unsigned b5:1;
		unsigned b6:1;
		unsigned b7:1;
		}flag10bit;
}myflag10;
#define rec_status            myflag10.flag10 
#define main_rec_err          myflag10.flag10bit.b0 
#define work                  myflag10.flag10bit.b1
#define miejun_result         myflag10.flag10bit.b2
#define door_switch           myflag10.flag10bit.b3
#define open_fmq              myflag10.flag10bit.b4
#define water_need_close_door myflag10.flag10bit.b5
#define Main_test             myflag10.flag10bit.b6          // mcq 130122 

//发现bits1和bitss的地址是同一个地址
typedef union
{
	unsigned char bits1;
	unsigned char bits2;
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
#define rec_status1	mytest.bits1
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
	rec_status1=0x11;
	R_1=1;
	R_2=1;
	R_3=1;
	R_4=1;
	R_5=0;
	R_6=1;
	R_7=1;
	R_8=1;
	
	printf("mytest=%x\n",*(unsigned char*)(&mytest));
	printf("Pbitss=%p\n",&mytest.bitss);
	printf("bits1=%p\n",&mytest.bits1);
	printf("bits2=%p\n",&mytest.bits2);

}