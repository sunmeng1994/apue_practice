#include<pthread.h>
#include<stdio.h>
void * thread_func1(void*arg)
{
    printf("thread1 returnning\n");
    return((void*)1);
}
void * thread_func2(void*arg)
{
    printf("thread2 exiting\n");
    pthread_exit((void*)2);
}

int main()
{
    int err;
    pthread_t tid1,tid2;
    void * thread_return_status;
    err=pthread_create(&tid1,NULL,thread_func1,NULL);
    if(err!=0)
	printf("can`t create thread1\n");
    err=pthread_create(&tid2,NULL,thread_func2,NULL);
    if(err!=0)
	printf("can`t create thread2\n");
    
    err=pthread_join(tid1,&thread_return_status);
    if(err!=0)
	printf("can`t join with thread1\n");
    printf("thread1 exit code%ld\n",(long)thread_return_status);
    
    err=pthread_join(tid2,&thread_return_status);
    if(err!=0)
	printf("can`t join with thread2\n");
    printf("thread2 exit code%ld\n",(long)thread_return_status);
    return 0;
}
