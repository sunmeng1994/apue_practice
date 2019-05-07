#include<stdio.h>
#include<time.h>
#include<sys/time.h>
void print_tms_struct()
void timesTest()
{
    struct tms t1;
    int i=0;
    
    for(i=0;i<10000;i++)
	getppid();
    
}
int main()
{
    long a1=clock();
    int i=0; 
    for(i=0;i<10000;i++)
	getppid();
    long a2=clock();
    printf("%ld,%ld\n",a1,a2);
    return 0;
}
