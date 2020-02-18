#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//一共有几位数XXX.XXX.XXX.XXX,最后一个和逗号判断


static char  item[16][26] ={0};

unsigned char ipgate_buf[128];

//将字符串XXX.XXX.XXX.XXX格式抓换成ip地址的格式自动识别.和.之间的字符个数
void get_ip(char *buf)
{
	unsigned char ip_count[4]= {0};
	char *p1=NULL;
	char *p2=NULL;
	char *p3=NULL;
	char *p4=NULL;
	p1=strstr(buf,".");
	//printf("p1-buf=%d\n",p1-buf);
	p2=strstr(p1+1,".");
	//printf("p2-p1=%d\n",p2-p1-1);
	p3=strstr(p2+1,".");
	//printf("p3-p2=%d\n",p3-p2-1);
	p4=strstr(p3+1,",");
	//printf("p4-p3=%d\n",p4-p3-1);
	ip_count[0]=p1-buf;
	ip_count[1]=p2-p1-1;
	ip_count[2]=p3-p2-1;
	ip_count[3]=p4-p3-1;
	
	if(ip_count[0]==3){
		if(ip_count[1]==3){//XXX.XXX
			if(ip_count[2]==3){//XXX.XXX.XXX.
				if(ip_count[3]==3){//XXX.XXX.XXX.XXX
					sprintf(item[8],"ip=%c%c%c.%c%c%c.%c%c%c.%c%c%c\n",
					*(buf+0),*(buf+1),*(buf+2),
					*(buf+4),*(buf+5),*(buf+6),
					*(buf+8),*(buf+9),*(buf+10),
					*(buf+12),*(buf+13),*(buf+14));
				}else if(ip_count[3]==2){//XXX.XXX.XXX.XX
					sprintf(item[8],"ip=%c%c%c.%c%c%c.%c%c%c.%c%c\n",
					*(buf+0),*(buf+1),*(buf+2),
					*(buf+4),*(buf+5),*(buf+6),
					*(buf+8),*(buf+9),*(buf+10),
					*(buf+12),*(buf+13));
				}else{///XXX.XXX.XXX.X
					sprintf(item[8],"ip=%c%c%c.%c%c%c.%c%c%c.%c\n",
					*(buf+0),*(buf+1),*(buf+2),
					*(buf+4),*(buf+5),*(buf+6),
					*(buf+8),*(buf+9),*(buf+10),
					*(buf+12));
				}
			}else if(ip_count[2]==2){//XXX.XXX.XX.
				if(ip_count[3]==3){//XXX.XXX.XX.XXX
					sprintf(item[8],"ip=%c%c%c.%c%c%c.%c%c.%c%c%c\n",
					*(buf+0),*(buf+1),*(buf+2),
					*(buf+4),*(buf+5),*(buf+6),
					*(buf+8),*(buf+9),
					*(buf+11),*(buf+12),*(buf+13));
				}else if(ip_count[3]==2){//XXX.XXX.XX.XX
					sprintf(item[8],"ip=%c%c%c.%c%c%c.%c%c.%c%c\n",
					*(buf+0),*(buf+1),*(buf+2),
					*(buf+4),*(buf+5),*(buf+6),
					*(buf+8),*(buf+9),
					*(buf+11),*(buf+12));
				}else{///XXX.XXX.XX.X
					sprintf(item[8],"ip=%c%c%c.%c%c%c.%c%c.%c\n",
					*(buf+0),*(buf+1),*(buf+2),
					*(buf+4),*(buf+5),*(buf+6),
					*(buf+8),*(buf+9),
					*(buf+11));
				}
			}else{//XXX.XXX.x
				if(ip_count[3]==3){//XXX.XXX.X.XXX
					sprintf(item[8],"ip=%c%c%c.%c%c%c.%c.%c%c%c\n",
					*(buf+0),*(buf+1),*(buf+2),
					*(buf+4),*(buf+5),*(buf+6),
					*(buf+8),
					*(buf+10),*(buf+11),*(buf+12));
				}else if(ip_count[3]==2){//XXX.XXX.X.XX
					sprintf(item[8],"ip=%c%c%c.%c%c%c.%c.%c%c\n",
					*(buf+0),*(buf+1),*(buf+2),
					*(buf+4),*(buf+5),*(buf+6),
					*(buf+8),
					*(buf+10),*(buf+11));
				}else{///XXX.XXX.X.X
					sprintf(item[8],"ip=%c%c%c.%c%c%c.%c.%c\n",
					*(buf+0),*(buf+1),*(buf+2),
					*(buf+4),*(buf+5),*(buf+6),
					*(buf+8),
					*(buf+10));
				}
			}
		}else if(ip_count[1]==2){//XXX.XX
			if(ip_count[2]==3){//XXX.XX.XXX.
				if(ip_count[3]==3){//XXX.XX.XXX.XXX
					sprintf(item[8],"ip=%c%c%c.%c%c.%c%c%c.%c%c%c\n",
					*(buf+0),*(buf+1),*(buf+2),
					*(buf+4),*(buf+5),
					*(buf+7),*(buf+8),*(buf+9),
					*(buf+11),*(buf+12),*(buf+13));
				}else if(ip_count[3]==2){//XXX.XX.XXX.XX
					sprintf(item[8],"ip=%c%c%c.%c%c.%c%c%c.%c%c\n",
					*(buf+0),*(buf+1),*(buf+2),
					*(buf+4),*(buf+5),
					*(buf+7),*(buf+8),*(buf+9),
					*(buf+11),*(buf+12));
				}else{///XXX.XX.XXX.X
					sprintf(item[8],"ip=%c%c%c.%c%c.%c%c%c.%c\n",
					*(buf+0),*(buf+1),*(buf+2),
					*(buf+4),*(buf+5),
					*(buf+7),*(buf+8),*(buf+9),
					*(buf+11));
				}
			}else if(ip_count[2]==2){//XXX.XX.XX.
				if(ip_count[3]==3){//XXX.XX.XX.XXX
					sprintf(item[8],"ip=%c%c%c.%c%c.%c%c.%c%c%c\n",
					*(buf+0),*(buf+1),*(buf+2),
					*(buf+4),*(buf+5),
					*(buf+7),*(buf+8),
					*(buf+10),*(buf+11),*(buf+12));
				}else if(ip_count[3]==2){//XXX.XX.XX.XX
					sprintf(item[8],"ip=%c%c%c.%c%c.%c%c.%c%c\n",
					*(buf+0),*(buf+1),*(buf+2),
					*(buf+4),*(buf+5),
					*(buf+7),*(buf+8),
					*(buf+10),*(buf+11));
				}else{///XXX.XX.XX.X
					sprintf(item[8],"ip=%c%c%c.%c%c.%c%c.%c\n",
					*(buf+0),*(buf+1),*(buf+2),
					*(buf+4),*(buf+5),
					*(buf+7),*(buf+8),
					*(buf+10));
				}
			}else{//XXX.XX.x
				if(ip_count[3]==3){//XXX.XX.X.XXX
					sprintf(item[8],"ip=%c%c%c.%c%c.%c.%c%c%c\n",
					*(buf+0),*(buf+1),*(buf+2),
					*(buf+4),*(buf+5),
					*(buf+7),
					*(buf+9),*(buf+10),*(buf+11));
				}else if(ip_count[3]==2){//XXX.XX.X.XX
					sprintf(item[8],"ip=%c%c%c.%c%c.%c.%c%c\n",
					*(buf+0),*(buf+1),*(buf+2),
					*(buf+4),*(buf+5),
					*(buf+7),
					*(buf+9),*(buf+10));
				}else{///XXX.XX.X.X
					sprintf(item[8],"ip=%c%c%c.%c%c.%c.%c\n",
					*(buf+0),*(buf+1),*(buf+2),
					*(buf+4),*(buf+5),
					*(buf+7),
					*(buf+9));
				}
			}
		}else{
			if(ip_count[2]==3){//XXX.X.XXX.
				if(ip_count[3]==3){//XXX.X.XXX.XXX
					sprintf(item[8],"ip=%c%c%c.%c.%c%c%c.%c%c%c\n",
					*(buf+0),*(buf+1),*(buf+2),
					*(buf+4),
					*(buf+6),*(buf+7),*(buf+8),
					*(buf+10),*(buf+11),*(buf+12));
				}else if(ip_count[3]==2){//XXX.X.XXX.XX
					sprintf(item[8],"ip=%c%c%c.%c.%c%c%c.%c%c\n",
					*(buf+0),*(buf+1),*(buf+2),
					*(buf+4),
					*(buf+6),*(buf+7),*(buf+8),
					*(buf+10),*(buf+11));
				}else{///XXX.X.XXX.X
					sprintf(item[8],"ip=%c%c%c.%c.%c%c%c.%c\n",
					*(buf+0),*(buf+1),*(buf+2),
					*(buf+4),
					*(buf+6),*(buf+7),*(buf+8),
					*(buf+10));
				}
			}else if(ip_count[2]==2){//XXX.X.XX.
				if(ip_count[3]==3){//XXX.X.XX.XXX
					sprintf(item[8],"ip=%c%c%c.%c.%c%c.%c%c%c\n",
					*(buf+0),*(buf+1),*(buf+2),
					*(buf+4),
					*(buf+6),*(buf+7),
					*(buf+9),*(buf+10),*(buf+11));
				}else if(ip_count[3]==2){//XXX.X.XX.XX
					sprintf(item[8],"ip=%c%c%c.%c.%c%c.%c%c\n",
					*(buf+0),*(buf+1),*(buf+2),
					*(buf+4),
					*(buf+6),*(buf+7),
					*(buf+9),*(buf+10));
				}else{///XXX.X.XX.X
					sprintf(item[8],"ip=%c%c%c.%c.%c%c.%c\n",
					*(buf+0),*(buf+1),*(buf+2),
					*(buf+4),
					*(buf+6),*(buf+7),
					*(buf+9));
				}
			}else{//XXX.X.x
				if(ip_count[3]==3){//XXX.X.X.XXX
					sprintf(item[8],"ip=%c%c%c.%c.%c.%c%c%c\n",
					*(buf+0),*(buf+1),*(buf+2),
					*(buf+4),
					*(buf+6),
					*(buf+8),*(buf+9),*(buf+10));
				}else if(ip_count[3]==2){//XXX.X.X.XX
					sprintf(item[8],"ip=%c%c%c.%c.%c.%c%c\n",
					*(buf+0),*(buf+1),*(buf+2),
					*(buf+4),
					*(buf+6),
					*(buf+8),*(buf+9));
				}else{///XXX.X.X.X
					sprintf(item[8],"ip=%c%c%c.%c.%c.%c\n",
					*(buf+0),*(buf+1),*(buf+2),
					*(buf+4),
					*(buf+6),
					*(buf+8));
				}
			}
		}
	}else if(ip_count[0]==2){//XX.
		if(ip_count[1]==3){//XX.XXX
			if(ip_count[2]==3){//XX.XXX.XXX.
				if(ip_count[3]==3){//XX.XXX.XXX.XXX
					sprintf(item[8],"ip=%c%c.%c%c%c.%c%c%c.%c%c%c\n",
					*(buf+0),*(buf+1),
					*(buf+3),*(buf+4),*(buf+5),
					*(buf+7),*(buf+8),*(buf+9),
					*(buf+11),*(buf+12),*(buf+13));
				}else if(ip_count[3]==2){//XX.XXX.XXX.XX
					sprintf(item[8],"ip=%c%c.%c%c%c.%c%c%c.%c%c\n",
					*(buf+0),*(buf+1),
					*(buf+3),*(buf+4),*(buf+5),
					*(buf+7),*(buf+8),*(buf+9),
					*(buf+11),*(buf+12));
				}else{///XX.XXX.XXX.X
					sprintf(item[8],"ip=%c%c.%c%c%c.%c%c%c.%c\n",
					*(buf+0),*(buf+1),
					*(buf+3),*(buf+4),*(buf+5),
					*(buf+7),*(buf+8),*(buf+9),
					*(buf+11));
				}
			}else if(ip_count[2]==2){//XX.XXX.XX.
				if(ip_count[3]==3){//XX.XXX.XX.XXX
					sprintf(item[8],"ip=%c%c.%c%c%c.%c%c.%c%c%c\n",
					*(buf+0),*(buf+1),
					*(buf+3),*(buf+4),*(buf+5),
					*(buf+7),*(buf+8),
					*(buf+10),*(buf+11),*(buf+12));
				}else if(ip_count[3]==2){//XX.XXX.XX.XX
					sprintf(item[8],"ip=%c%c.%c%c%c.%c%c.%c%c\n",
					*(buf+0),*(buf+1),
					*(buf+3),*(buf+4),*(buf+5),
					*(buf+7),*(buf+8),
					*(buf+10),*(buf+11));
				}else{///XX.XXX.XX.X
					sprintf(item[8],"ip=%c%c.%c%c%c.%c%c.%c\n",
					*(buf+0),*(buf+1),
					*(buf+3),*(buf+4),*(buf+5),
					*(buf+7),*(buf+8),
					*(buf+10),*(buf+11));
				}
			}else{//XX.XXX.x
				if(ip_count[3]==3){//XX.XXX.X.XXX
					sprintf(item[8],"ip=%c%c.%c%c%c.%c.%c%c%c\n",
					*(buf+0),*(buf+1),
					*(buf+3),*(buf+4),*(buf+5),
					*(buf+7),
					*(buf+9),*(buf+10),*(buf+11));
				}else if(ip_count[3]==2){//XX.XXX.X.XX
					sprintf(item[8],"ip=%c%c.%c%c%c.%c.%c%c\n",
					*(buf+0),*(buf+1),
					*(buf+3),*(buf+4),*(buf+5),
					*(buf+7),
					*(buf+9),*(buf+10));
				}else{///XX.XXX.X.X
					sprintf(item[8],"ip=%c%c.%c%c%c.%c.%c\n",
					*(buf+0),*(buf+1),
					*(buf+3),*(buf+4),*(buf+5),
					*(buf+7),
					*(buf+9));
				}
			}
		}else if(ip_count[1]==2){//XX.XX
			if(ip_count[2]==3){//XX.XX.XXX.
				if(ip_count[3]==3){//XX.XX.XXX.XXX
					sprintf(item[8],"ip=%c%c.%c%c.%c%c%c.%c%c%c\n",
					*(buf+0),*(buf+1),
					*(buf+3),*(buf+4),
					*(buf+6),*(buf+7),*(buf+8),
					*(buf+10),*(buf+11),*(buf+12));
				}else if(ip_count[3]==2){//XX.XX.XXX.XX
					sprintf(item[8],"ip=%c%c.%c%c.%c%c%c.%c%c\n",
					*(buf+0),*(buf+1),
					*(buf+3),*(buf+4),
					*(buf+6),*(buf+7),*(buf+8),
					*(buf+10),*(buf+11));
				}else{///XX.XX.XXX.X
					sprintf(item[8],"ip=%c%c.%c%c.%c%c%c.%c\n",
					*(buf+0),*(buf+1),
					*(buf+3),*(buf+4),
					*(buf+6),*(buf+7),*(buf+8),
					*(buf+10));
				}
			}else if(ip_count[2]==2){//XX.XX.XX.
				if(ip_count[3]==3){//XX.XX.XX.XXX
					sprintf(item[8],"ip=%c%c.%c%c.%c%c.%c%c%c\n",
					*(buf+0),*(buf+1),
					*(buf+3),*(buf+4),
					*(buf+6),*(buf+7),
					*(buf+9),*(buf+10),*(buf+11));
				}else if(ip_count[3]==2){//XX.XX.XX.XX
					sprintf(item[8],"ip=%c%c.%c%c.%c%c.%c%c\n",
					*(buf+0),*(buf+1),
					*(buf+3),*(buf+4),
					*(buf+6),*(buf+7),
					*(buf+9),*(buf+10));
				}else{///XX.XX.XX.X
					sprintf(item[8],"ip=%c%c.%c%c.%c%c.%c\n",
					*(buf+0),*(buf+1),
					*(buf+3),*(buf+4),
					*(buf+6),*(buf+7),
					*(buf+9));
				}
			}else{//XX.XX.x
				if(ip_count[3]==3){//XX.XX.X.XXX
					sprintf(item[8],"ip=%c%c.%c%c.%c.%c%c%c\n",
					*(buf+0),*(buf+1),
					*(buf+3),*(buf+4),
					*(buf+6),
					*(buf+8),*(buf+9),*(buf+10));
				}else if(ip_count[3]==2){//XX.XX.X.XX
					sprintf(item[8],"ip=%c%c.%c%c.%c.%c%c\n",
					*(buf+0),*(buf+1),
					*(buf+3),*(buf+4),
					*(buf+6),
					*(buf+8),*(buf+9));
				}else{///XX.XX.X.X
					sprintf(item[8],"ip=%c%c.%c%c.%c.%c\n",
					*(buf+0),*(buf+1),
					*(buf+3),*(buf+4),
					*(buf+6),
					*(buf+8));
				}
			}
		}else{
			if(ip_count[2]==3){//XX.X.XXX.
				if(ip_count[3]==3){//XX.X.XXX.XXX
					sprintf(item[8],"ip=%c%c.%c.%c%c%c.%c%c%c\n",
					*(buf+0),*(buf+1),
					*(buf+3),
					*(buf+5),*(buf+6),*(buf+7),
					*(buf+9),*(buf+10),*(buf+11));
				}else if(ip_count[3]==2){//XX.X.XXX.XX
					sprintf(item[8],"ip=%c%c.%c.%c%c%c.%c%c\n",
					*(buf+0),*(buf+1),
					*(buf+3),
					*(buf+5),*(buf+6),*(buf+7),
					*(buf+9),*(buf+10));
				}else{///XX.X.XXX.X
					sprintf(item[8],"ip=%c%c.%c.%c%c%c.%c\n",
					*(buf+0),*(buf+1),
					*(buf+3),
					*(buf+5),*(buf+6),*(buf+7),
					*(buf+9));
				}
			}else if(ip_count[2]==2){//XX.X.XX.
				if(ip_count[3]==3){//XX.X.XX.XXX
					sprintf(item[8],"ip=%c%c.%c.%c%c.%c%c%c\n",
					*(buf+0),*(buf+1),
					*(buf+3),
					*(buf+5),*(buf+6),
					*(buf+8),*(buf+9),*(buf+10));
				}else if(ip_count[3]==2){//XX.X.XX.XX
					sprintf(item[8],"ip=%c%c.%c.%c%c.%c%c\n",
					*(buf+0),*(buf+1),
					*(buf+3),
					*(buf+5),*(buf+6),
					*(buf+8),*(buf+9));
				}else{///XX.X.XX.X
					sprintf(item[8],"ip=%c%c.%c.%c%c.%c\n",
					*(buf+0),*(buf+1),
					*(buf+3),
					*(buf+5),*(buf+6),
					*(buf+8));
				}
			}else{//XX.X.x
				if(ip_count[3]==3){//XX.X.X.XXX
					sprintf(item[8],"ip=%c%c.%c.%c.%c%c%c\n",
					*(buf+0),*(buf+1),
					*(buf+3),
					*(buf+5),
					*(buf+7),*(buf+8),*(buf+9));
				}else if(ip_count[3]==2){//XX.X.X.XX
					sprintf(item[8],"ip=%c%c.%c.%c.%c%c\n",
					*(buf+0),*(buf+1),
					*(buf+3),
					*(buf+5),
					*(buf+7),*(buf+8));
				}else{///XX.X.X.X
					sprintf(item[8],"ip=%c%c.%c.%c.%c\n",
					*(buf+0),*(buf+1),
					*(buf+3),
					*(buf+5),
					*(buf+7));
				}
			}
		}
	}else{//X.
		if(ip_count[1]==3){//X.XXX
			if(ip_count[2]==3){//X.XXX.XXX.
				if(ip_count[3]==3){//X.XXX.XXX.XXX
					sprintf(item[8],"ip=%c.%c%c%c.%c%c%c.%c%c%c\n",
					*(buf+0),
					*(buf+2),*(buf+3),*(buf+4),
					*(buf+6),*(buf+7),*(buf+8),
					*(buf+10),*(buf+11),*(buf+12));
				}else if(ip_count[3]==2){//X.XXX.XXX.XX
					sprintf(item[8],"ip=%c.%c%c%c.%c%c%c.%c%c\n",
					*(buf+0),
					*(buf+2),*(buf+3),*(buf+4),
					*(buf+6),*(buf+7),*(buf+8),
					*(buf+10),*(buf+11));
				}else{///X.XXX.XXX.X
					sprintf(item[8],"ip=%c.%c%c%c.%c%c%c.%c\n",
					*(buf+0),
					*(buf+2),*(buf+3),*(buf+4),
					*(buf+6),*(buf+7),*(buf+8),
					*(buf+10));
				}
			}else if(ip_count[2]==2){//X.XXX.XX.
				if(ip_count[3]==3){//X.XXX.XX.XXX
					sprintf(item[8],"ip=%c.%c%c%c.%c%c.%c%c%c\n",
					*(buf+0),
					*(buf+2),*(buf+3),*(buf+4),
					*(buf+6),*(buf+7),
					*(buf+9),*(buf+10),*(buf+11));
				}else if(ip_count[3]==2){//X.XXX.XX.XX
					sprintf(item[8],"ip=%c.%c%c%c.%c%c.%c%c\n",
					*(buf+0),
					*(buf+2),*(buf+3),*(buf+4),
					*(buf+6),*(buf+7),
					*(buf+9),*(buf+10));
				}else{///X.XXX.XX.X
					sprintf(item[8],"ip=%c.%c%c%c.%c%c.%c\n",
					*(buf+0),
					*(buf+2),*(buf+3),*(buf+4),
					*(buf+6),*(buf+7),
					*(buf+9));
				}
			}else{//X.XXX.x
				if(ip_count[3]==3){//X.XXX.X.XXX
					sprintf(item[8],"ip=%c.%c%c%c.%c.%c%c%c\n",
					*(buf+0),
					*(buf+2),*(buf+3),*(buf+4),
					*(buf+6),
					*(buf+8),*(buf+9),*(buf+10));
				}else if(ip_count[3]==2){//X.XXX.X.XX
					sprintf(item[8],"ip=%c.%c%c%c.%c.%c%c\n",
					*(buf+0),
					*(buf+2),*(buf+3),*(buf+4),
					*(buf+6),
					*(buf+8),*(buf+9));
				}else{///X.XXX.X.X
					sprintf(item[8],"ip=%c.%c%c%c.%c.%c\n",
					*(buf+0),
					*(buf+2),*(buf+3),*(buf+4),
					*(buf+6),
					*(buf+8));
				}
			}
		}else if(ip_count[1]==2){//X.XX
			if(ip_count[2]==3){//X.XX.XXX.
				if(ip_count[3]==3){//X.XX.XXX.XXX
					sprintf(item[8],"ip=%c.%c%c.%c%c%c.%c%c%c\n",
					*(buf+0),
					*(buf+2),*(buf+3),
					*(buf+5),*(buf+6),*(buf+7),
					*(buf+9),*(buf+10),*(buf+11));
				}else if(ip_count[3]==2){//X.XX.XXX.XX
					sprintf(item[8],"ip=%c.%c%c.%c%c%c.%c%c\n",
					*(buf+0),
					*(buf+2),*(buf+3),
					*(buf+5),*(buf+6),*(buf+7),
					*(buf+9),*(buf+10));
				}else{///X.XX.XXX.X
					sprintf(item[8],"ip=%c.%c%c.%c%c%c.%c\n",
					*(buf+0),
					*(buf+2),*(buf+3),
					*(buf+5),*(buf+6),*(buf+7),
					*(buf+9));
				}
			}else if(ip_count[2]==2){//X.XX.XX.
				if(ip_count[3]==3){//X.XX.XX.XXX
					sprintf(item[8],"ip=%c.%c%c.%c%c.%c%c%c\n",
					*(buf+0),
					*(buf+2),*(buf+3),
					*(buf+5),*(buf+6),
					*(buf+8),*(buf+9),*(buf+10));
				}else if(ip_count[3]==2){//X.XX.XX.XX
					sprintf(item[8],"ip=%c.%c%c.%c%c.%c%c\n",
					*(buf+0),
					*(buf+2),*(buf+3),
					*(buf+5),*(buf+6),
					*(buf+8),*(buf+9));
				}else{///X.XX.XX.X
					sprintf(item[8],"ip=%c.%c%c.%c%c.%c\n",
					*(buf+0),
					*(buf+2),*(buf+3),
					*(buf+5),*(buf+6),
					*(buf+8));
				}
			}else{//X.XX.x
				if(ip_count[3]==3){//X.XX.X.XXX
					sprintf(item[8],"ip=%c.%c%c.%c.%c%c%c\n",
					*(buf+0),
					*(buf+2),*(buf+3),
					*(buf+5),
					*(buf+7),*(buf+8),*(buf+9));
				}else if(ip_count[3]==2){//X.XX.X.XX
					sprintf(item[8],"ip=%c.%c%c.%c.%c%c\n",
					*(buf+0),
					*(buf+2),*(buf+3),
					*(buf+5),
					*(buf+7),*(buf+8));
				}else{///X.XX.X.X
					sprintf(item[8],"ip=%c.%c%c.%c.%c\n",
					*(buf+0),
					*(buf+2),*(buf+3),
					*(buf+5),
					*(buf+7));
				}
			}
		}else{
			if(ip_count[2]==3){//X.X.XXX.
				if(ip_count[3]==3){//X.X.XXX.XXX
					sprintf(item[8],"ip=%c.%c.%c%c%c.%c%c%c\n",
					*(buf+0),
					*(buf+2),
					*(buf+4),*(buf+5),*(buf+6),
					*(buf+8),*(buf+9),*(buf+10));
				}else if(ip_count[3]==2){//X.X.XXX.XX
					sprintf(item[8],"ip=%c.%c.%c%c%c.%c%c\n",
					*(buf+0),
					*(buf+2),
					*(buf+4),*(buf+5),*(buf+6),
					*(buf+8),*(buf+9));
				}else{///X.X.XXX.X
					sprintf(item[8],"ip=%c.%c.%c%c%c.%c\n",
					*(buf+0),
					*(buf+2),
					*(buf+4),*(buf+5),*(buf+6),
					*(buf+8));
				}
			}else if(ip_count[2]==2){//X.X.XX.
				if(ip_count[3]==3){//X.X.XX.XXX
					sprintf(item[8],"ip=%c.%c.%c%c.%c%c%c\n",
					*(buf+0),
					*(buf+2),
					*(buf+4),*(buf+5),
					*(buf+7),*(buf+8),*(buf+9));
				}else if(ip_count[3]==2){//X.X.XX.XX
					sprintf(item[8],"ip=%c.%c.%c%c.%c%c\n",
					*(buf+0),
					*(buf+2),
					*(buf+4),*(buf+5),
					*(buf+7),*(buf+8));
				}else{///X.X.XX.X
					sprintf(item[8],"ip=%c.%c.%c%c.%c\n",
					*(buf+0),
					*(buf+2),
					*(buf+4),*(buf+5),
					*(buf+7));
				}
			}else{//X.X.x
				if(ip_count[3]==3){//X.X.X.XXX
					sprintf(item[8],"ip=%c.%c.%c.%c%c%c\n",
					*(buf+0),
					*(buf+2),
					*(buf+4),
					*(buf+6),*(buf+7),*(buf+8));
				}else if(ip_count[3]==2){//X.X.X.XX
					sprintf(item[8],"ip=%c.%c.%c.%c%c\n",
					*(buf+0),
					*(buf+2),
					*(buf+4),
					*(buf+6),*(buf+7));
				}else{///X.X.X.X
					sprintf(item[8],"ip=%c.%c.%c.%c\n",
					*(buf+0),
					*(buf+2),
					*(buf+4),
					*(buf+6));
				}
			}
		}
	}
		
}

void get_gateway(char *buf)
{
	char *p1=NULL;
	char *p2=NULL;
	char *p3=NULL;
	char item_buf[26];
	unsigned char i;
	p1=strstr(buf,".");
	p1=strstr(p1+1,".");
	p1=strstr(p1+1,".");
	p1=strstr(p1+1,".");
	p1=strstr(p1+1,".");
	p1=strstr(p1+1,".");
	p1=strstr(p1+1,".");
	p1=strstr(p1+1,".");
	p1=strstr(p1+1,".");
	//printf("p1=%s\n",p1);
	p2=strstr(p1+1,"\r\n");
	//printf("p2=%s\n",p2);
	//printf("p2-p1=%d\n",p2-p1-1);
	memcpy(item_buf,&item[8],sizeof(item[8]));
	//printf("item_buf=%s\n",item_buf);
	p3=strstr((char*)&item[8],".");
	p3=strstr(p3+1,".");
	p3=strstr(p3+1,".");
	//printf("p3=%s\n",p3);
	for(i=0;i<p2-p1-1;i++){
		*(p3+1+i)=*(p1+1+i);
	}
	*(p3+1+(p2-p1-1))='\0';
	//printf("p3=%s\n",p3);
	//memcpy(&item[9],&item[8],sizeof(item[8]));
	sprintf(item[9],"gateway=%s\n",(char*)(&item[8])+3);
	memcpy(&item[8],item_buf,sizeof(item[8]));
	printf("item[8]=%s",(char*)&item[8]);
	printf("item[9]=%s",(char*)&item[9]);	
}



int main()
{
	char ipgate_buf[128];
	ipgate_buf[39]= 0x2c;
	ipgate_buf[40] = 0x31;
	ipgate_buf[41] = 0x39;
	ipgate_buf[42] = 0x32;
	ipgate_buf[43] = 0x2e;
	ipgate_buf[44] = 0x31;
	ipgate_buf[45] = 0x36;
	ipgate_buf[46] = 0x38;
	ipgate_buf[47] = 0x2e;
	ipgate_buf[48] = 0x34;
	ipgate_buf[49] = 0x33;
	ipgate_buf[50] = 0x2e;
	ipgate_buf[51] = 0x33;
	ipgate_buf[52] = 0x39;
	ipgate_buf[53] = 0x2c;
	ipgate_buf[54] = 0x32;
	ipgate_buf[55] = 0x35;
	ipgate_buf[56] = 0x35;
	ipgate_buf[57] = 0x2e;
	ipgate_buf[58] = 0x32;
	ipgate_buf[59] = 0x35;
	ipgate_buf[60] = 0x35;
	ipgate_buf[61] = 0x2e;
	ipgate_buf[62] = 0x32;
	ipgate_buf[63] = 0x35;
	ipgate_buf[64] = 0x35;
	ipgate_buf[65] = 0x2e;
	ipgate_buf[66] = 0x30;
	ipgate_buf[67] = 0x2c;
	ipgate_buf[68] = 0x31;
	ipgate_buf[69] = 0x39;
	ipgate_buf[70] = 0x32;
	ipgate_buf[71] = 0x2e;
	ipgate_buf[72] = 0x31;
	ipgate_buf[73] = 0x36;
	ipgate_buf[74] = 0x38;
	ipgate_buf[75] = 0x2e;
	ipgate_buf[76] = 0x34;
	ipgate_buf[77] = 0x33;
	ipgate_buf[78] = 0x2e;
	ipgate_buf[79] = 0x31;
	ipgate_buf[80] = 0xd;
	ipgate_buf[81] = 0xa;
	ipgate_buf[82] = 0x0;
	
	
/* 	ipgate_buf[39] = 0x2c;
	ipgate_buf[40] = 0x31;
	ipgate_buf[41] = 0x37;
	ipgate_buf[42] = 0x32;
	ipgate_buf[43] = 0x2e;
	ipgate_buf[44] = 0x32;
	ipgate_buf[45] = 0x30;
	ipgate_buf[46] = 0x2e;
	ipgate_buf[47] = 0x31;
	ipgate_buf[48] = 0x30;
	ipgate_buf[49] = 0x2e;
	ipgate_buf[50] = 0x33;
	ipgate_buf[51] = 0x2c, */
	get_ip(&ipgate_buf[40]);
	get_gateway(&ipgate_buf[40]);
	printf("%s\n",item[8]);
}