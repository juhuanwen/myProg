#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOG printf("%s|%d|",__FILE__,__LINE__);printf

#define TMP_SIZE 100
static  char *tmp;


int Change_Txt_File_Test()
{
	int ret = -1;
	FILE *pConfig = NULL;
	pConfig = fopen("config","w");
	if(pConfig){
		fprintf(pConfig,"temperature=%.1f\n",1.1);
		fclose(pConfig);
		ret=1;
	}
	
	return ret;
}

int Change_tmp_Content()
{
	snprintf(tmp,TMP_SIZE,"temperature=%.1f\n",1.1);
}

int main(int argc,char **argv)
{
	tmp=malloc(TMP_SIZE);
	Change_Txt_File_Test();
	Change_tmp_Content();
	LOG("tmp=%s\n",tmp);
	free(tmp);
}