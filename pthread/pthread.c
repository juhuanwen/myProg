#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <sys/time.h>

#define MAX 10
pthread_t thread[2];
pthread_mutex_t mut;
int number=0;
int i;
void * thread1()
{
	printf("%s:I'm thread 1\n",__func__);
	for(i=0;i<MAX;i++){
		printf("%s:number=%d\n",__func__,number);
		pthread_mutex_lock(&mut);
		number++;
		pthread_mutex_unlock(&mut);
		usleep(100*1000);
	}
	printf("%s:done\n",__func__);
	pthread_exit(NULL);
} 


void * thread2()
{
	printf("%s:I'm thread 2\n",__func__);
	for(i=0;i<MAX;i++){
		printf("%s:number=%d\n",__func__,number);
		pthread_mutex_lock(&mut);
		number++;
		pthread_mutex_unlock(&mut);
		usleep(100*1000);
	}
	printf("%s:done\n",__func__);
	pthread_exit(NULL);
} 

void thread_create(void)
{
	int temp;
	memset(&thread,0,sizeof(thread));
	if(temp=pthread_create(&thread[1],NULL,thread1,NULL))
		printf("create thread1 fail\n");
	else
		printf("create thread1 success\n");
	if(temp=pthread_create(&thread[0],NULL,thread2,NULL))
		printf("create thread2 fail\n");
	else
		printf("create thread2 success\n");
}
void thread_wait(void)
{
	if(thread[0]!=0){
		pthread_join(thread[0],NULL);
		printf("thread1 exit\n");
	}
	if(thread[1]!=0){
		pthread_join(thread[1],NULL);
		printf("thread2 exit\n");
	}
}

int main()
{
	pthread_mutex_init(&mut,NULL);
	printf("main function creating...\n");
	thread_create();
	printf("main function waiting threads exit...\n");
	thread_wait();
	return 0;
}
