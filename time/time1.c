#include "time1.h"
#include <time.h>
#include <stdio.h>

typedef struct
{
    time_t record_time;//8
    float  record_temp;//4
    float  record_humi;//4
} RECORD_DATA_STRU_TYPE;

// struct tm {
               // int tm_sec;    /* Seconds (0-60) */
               // int tm_min;    /* Minutes (0-59) */
               // int tm_hour;   /* Hours (0-23) */
               // int tm_mday;   /* Day of the month (1-31) */
               // int tm_mon;    /* Month (0-11) */
               // int tm_year;   /* Year - 1900 */
               // int tm_wday;   /* Day of the week (0-6, Sunday = 0) */
               // int tm_yday;   /* Day in the year (0-365, 1 Jan = 0) */
               // int tm_isdst;  /* Daylight saving time */
// };
//#define LOG printf("[%s][%4d]:",__FUNC__,__line__);printf
#define LOG printf("%s|%04d|", __FILE__, __LINE__); printf

time_t t;
struct tm *t1;

int main()
{
	t=time(NULL);
	RECORD_DATA_STRU_TYPE ss;
	LOG("sizeof(ss.record_temp)=%ld\n",sizeof(ss.record_temp));
	LOG("sizeof(ss.record_humi)=%ld\n",sizeof(ss.record_humi));
	LOG("sizeof(ss.record_time)=%ld\n",sizeof(ss.record_time));
	LOG("sizeof(ss)=%ld\n",sizeof(ss));
	//LOG("%s\n",ctime(&t));
	t1=localtime(&t);
	LOG("%d-%d-%d,%d-%d-%d\n",t1->tm_year,t1->tm_mon,t1->tm_mday,t1->tm_hour,t1->tm_min,t1->tm_sec);
	return 1;
}


