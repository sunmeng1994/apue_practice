#include<sys/time.h>
#include<time.h>
#include<stdio.h>

//include<sys/time.h>
//int gettimeofday(struct timeval *tv,struct timezone*tz);
//第二个参数已经废弃，传入NULL
//struct timeval{
//time_t tv_sec; //时间戳
//suseconds_t tv_usec;};// long int 额外微妙级，百万分之一
//
//#include<time>
//time_t time(time_t*a);
//返回的结果与*a一样，因此可以time_t t=time(NULL) 调用
//


int main()
{
    
    struct timeval ts1;
    int err=gettimeofday(&ts1,NULL);
    if(err!=0)
	printf("gettimeof day failed\n");
    printf("%ld,%ld\n",ts1.tv_sec,ts1.tv_usec);
    
    time_t time1;
    time_t time2=time(&time1);
    printf("%ld,%ld\n",time1,time2);
    return 0;
}

