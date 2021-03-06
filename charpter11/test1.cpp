#include<pthread.h>
#include<iostream>
#include<unistd.h>
using namespace std;
void printtid(const char*s)
{
    pid_t pid=getpid();
    pthread_t tid=pthread_self();
    cout<<s<<"pid:"<<pid<<"tid:"<<tid<<endl;
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
	cout<<"create thread failed"<<endl;
    printtid("main thread:");
    sleep(1);
    return 0;
}
