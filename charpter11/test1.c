#include<pthread.h>
#include<unistd.h>
#include<stdio.h>
void printtid(const char*s)
{
    pid_t pid=getpid();
    pthread_t tid=pthread_self();
    printf("%s,pid %lu,tid %lu,(0x%lx)\n",s,pid,tid,tid);
}
void*threadFunc(void*args)
{
    printtid("new thread:");
    return ((void*)0);
}
int main()
{
    pthread_t threadId;
    int err=pthread_create(&threadId,NULL,threadFunc,NULL);
    if(err!=0)
	printf("create thread failed");
    printtid("main thread:");
    sleep(1);
    return 0;
}
