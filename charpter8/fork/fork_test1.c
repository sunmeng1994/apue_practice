#include<stdio.h>
#include<unistd.h>
void printpid()
{
    //用ps -e可以看到父进程是bash
    int pid=getpid();
    int pid2=getppid();
    int uid=getuid();
    int uid2=geteuid();
    int gid=getgid();
    int gid2=getegid();
    printf("pid:%d,ppid:%d,uid:%d,euid:%d,gid:%d,egid:%d\n",
    pid,pid2,uid,uid2,gid,gid2);
}
int globalInt=999;
int main()
{
    printf("before fork\n");
    int i=fork();
    if(i<0)
	printf("fork error!\n");
    else if(i>0)
    {
	sleep(5);
	printf("i=%d,global=%d\n",i,globalInt);
	printpid();
    }
    else 
    {
	globalInt=1;
	printf("i=%d,global=%d\n",i,globalInt);
	printpid();
    }
    return 0;
}
