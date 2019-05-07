#include<sys/times.h>
#include<time.h>
#include<stdio.h>
#include<unistd.h>
void displayProcessTimes(const char * msg)
{
    struct tms t;
    clock_t clockTime;
    static long clockTicks=0;
    if(msg!=NULL)
	printf("%s",msg);
    if(clockTicks==0)
    {
	clockTicks=sysconf(_SC_CLK_TCK);
	if(clockTicks==-1)
	    printf("sysTime");
    }
    clockTime=clock();
    if(clockTime==-1)
	printf("clock");

    printf("clock() returns:%ld clock-per-sec(%.2f secs)\n",clockTime,(double)clockTime/CLOCKS_PER_SEC);

    if(times(&t)==-1)
	printf("times");
    printf("times() yields:user CPU=%.2f;systemCPu:%.2f\n",(double)t.tms_utime/clockTicks,(double)t.tms_stime/clockTicks);
}
int main()
{
    int numCalls,j;
    printf("CLOCKS_PER_SEC=%ld sysconf(_SC_CLK_TCK)-%ld\n",(long)CLOCKS_PER_SEC,sysconf(_SC_CLK_TCK));

    displayProcessTimes("At program start:\n");
    numCalls=1000000;
    for(j=0;j<numCalls;j++)
	getppid();
    displayProcessTimes("After loop:\n");

    return 0;
}
