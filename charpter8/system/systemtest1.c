#include<stdlib.h>
#include<stdio.h>
int main()
{
    if(system("date")<0)
	printf("fucking system failded\n");
    
    if(system("nosuchcommand")<0)
	printf("fucking system failed\n");
    
    if(system("who;exit 44")<0)
	printf("fucking system failed\n");

    return 0;    
}
