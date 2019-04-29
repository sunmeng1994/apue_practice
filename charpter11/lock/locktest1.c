#include<pthread.h>
#include<stdio.h>
//该项目主要是测试在不加锁的情况下，总数会不会发生错误。
int sum=0;
pthread_mutex_t mutex1=PTHREAD_MUTEX_INITIALIZER;
void*thread_func1()
{
    int i=0;
    for(i=0;i<1000000000;i++)
    {
	pthread_mutex_lock(&mutex1);
	sum++;
	pthread_mutex_unlock(&mutex1);
    }    
    return (void*)0;
}
void*thread_func2()
{
    int i=0;
    for(i=0;i<1000000000;i++)
    {
	pthread_mutex_lock(&mutex1);
	sum++;
	pthread_mutex_unlock(&mutex1);
    }    
    return (void*)0;
}
int main()
{
    long tid1,tid2;
    pthread_create(&tid1,NULL,thread_func1,NULL);
    pthread_create(&tid2,NULL,thread_func2,NULL);
    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL); 
    printf("%d\n",sum);

    pthread_mutex_destroy(&mutex1);
    return 0;
}
