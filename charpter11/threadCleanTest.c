#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
void cleanup(void*arg)
{
    printf("clean up:%s\n",(char*)arg);
}
void*thr_fn1(void*arg)
{
    printf("thread1 start\n");
    pthread_cleanup_push(cleanup,(char*)"thread1 first handler");
    pthread_cleanup_push(cleanup,(char*)"thread1 second handler");
    printf("thread1 push complete\n");
    if(arg)
	return ((void*)1);
    pthread_cleanup_pop(0);
    pthread_cleanup_pop(0);
    return((void*)1);
}
void*thr_fn2(void*arg)
{
    printf("thread 2 start\n");
    pthread_cleanup_push(cleanup,(char*)"thread2 first handler");
    pthread_cleanup_push(cleanup,(char*)"thread2 second handler");
    printf("thread 2 push complete\n");
    if(arg)
	pthread_exit((void*)2);
    pthread_cleanup_pop(0);
    pthread_cleanup_pop(0);
    pthread_exit((void*)2);
}
int main()
{
    int err;
    pthread_t tid1,tid2;
    void *tret;
    
    err=pthread_create(&tid1,NULL,thr_fn1,(void*)1);
    if(err!=0)
	printf("create thread1 failed\n"); 
    
    err=pthread_create(&tid2,NULL,thr_fn2,(void*)1);
    if(err!=0)
	printf("create thread2 failed\n");

    err=pthread_join(tid1,&tret);
    if(err!=0)
	printf("join thread1 failed\n");
    printf("thread1 exit code %ld\n",(long)tret);

    err=pthread_join(tid2,&tret);
    if(err!=0)
	printf("join thread2 failed\n");
    printf("thread2 exit code %ld\n",(long)tret);	
    
    return 0;
}
