#include<sys/wait.h>
#include<myerr.h>
void pr_exit(int status)
{
    if(WIFEXITED(status))
	printf("normal exit ,exit status =%d\n",WEXITSTATUS(status));
    else if(WIFSIGNALED(status))
	printf("signal number=%d%s\n",
	WTERMSIG(status),
#ifdef WCOREDUMP
	WCOREDUMP(status)?"(core file generated)":"");
#else
    );
#endif 
    else if(WIFSTOPPED(status))
	printf("child stoppped ,signal number=%d\n",WSTOPSIG(status));
}
int main()
{
    int pid;
    int status;
    
    //产生一个exit退出的子进程
    pid=fork();
    if(pid<0)
	printf("fork failed.\n");
    else if(pid==0)
    {
	printf("first pid is:%d\n",getpid());
	exit(7);
    }
    
    
    //产生一个abort结束的子进程
    pid=fork();
    if(pid<0)
	printf("fork failed.\n");
    else if(pid==0)
    {
	printf("second pid is:%d\n",getpid());
	abort();
    } 

    //产生一个异常退出的子进程
    if((pid=fork())<0)
	err_sys("fork error\n");
    else if(pid==0)
    {
	printf("third pid is:%d\n",getpid());
	status/=0;
    } 
    sleep(10);
   //通过多次测试，
   //多个僵尸进程，会wait第一个子进程 
    int wait_pid=wait(&status); 
    printf("wait pid is %d\n",wait_pid);
    if(wait_pid!=pid)
    {
	printf("wait error \n");
    }
    pr_exit(status); 
    sleep(10);
    exit(0);
}
