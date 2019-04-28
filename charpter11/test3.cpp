#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
struct foo{
    int a,b,c,d;
};
void printfoo(const char*s,const struct foo*fp)
{
    printf("%s",s);
    printf("struct at 0x%lx\n",(unsigned long)fp);
    printf("foo.a=%d\n",fp->a);
    printf("foo.b=%d\n",fp->b);
    printf("foo.c=%d\n",fp->c);
    printf("foo.d=%d\n",fp->d);
}
void * threadFunc1(void*arg)
{
    struct foo foo1={1,2,3,4};
    printfoo("thread 1:\n",&foo1);
    pthread_exit((void*)&foo1);
}
void * threadFunc2(void*arg)
{
    printf("thread 2: ID is %lu\n",(unsigned long)pthread_self());
    pthread_exit((void*)0);
}
int main()
{
    int err;
    pthread_t tid1,tid2;
    struct foo*fp;
    
    err=pthread_create(&tid1,NULL,threadFunc1,NULL);
    if(err!=0)
	printf("create thread1 failed\n");
    err=pthread_join(tid1,(void**)&fp);
    if(err!=0)
	printf("can`t join thread1\n");
    sleep(1);
    err=pthread_create(&tid2,NULL,threadFunc2,NULL);
    if(err!=0)
	printf("can`t create thread2");
    sleep(1);
    printfoo("parent:\n",fp);
    return 0;
}

