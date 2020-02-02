#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char u8;
#define LOG printf("%s|%d|  ",__FILE__,__LINE__); printf

int main()
{
	u8 ss[2][3];
	u8 i=0,j=0;
	for(i=0;i<6;i++){
		 *((u8*)ss+i)=i;
	}
	for(i=0;i<2;i++){
		for(j=0;j<3;j++){
			LOG("ss[%d][%d]=%d\n",i,j,ss[i][j]);
		}
	}
}