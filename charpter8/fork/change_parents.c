#include<stdio.h>
#include<unistd.h>

//如果父进程在子进程之前中止，会被init收养，ppid就会变成1
int main()
{
    printf("start\n");
    int n=fork();
    if(n<0)
    {
	printf("fork failed\n");
    }
    else if(n==0)
    {
	printf("pid:%d,ppid:%d\n",getpid(),getppid());    
	sleep(5);
	printf("pid:%d,ppid:%d\n",getpid(),getppid());
	return 0;    
    }
    else
    {
	sleep(1);
	return 0;
    }
}
