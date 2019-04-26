#include<pthread.h>
#include<iostream>
using namespace std;
void printtid(const char*s)
{
    long pid=getpid();
    long tid=pthread_self();
    cout<<s<<"pid:"<<pid<<"tid:"<<tid<<endl;
}
void threadFunc()
{
    cout<<"new thread:";
    return 0
}
int main()
{
    long threadId;
    err=pthread_create(&threadId,NULL,threadFunc,:)
    return 0;
}
