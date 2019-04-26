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
	exit(7);
    
    //产生一个abort结束的子进程
    pid=fork();
    if(pid<0)
	printf("fork failed.\n");
    else if(pid==0)
	abort();
   
    // 
    if(wait(&status)!=pid)
	err_sys("wait error\n");
    pr_exit(status);

    //产生一个异常退出的子进程
    if((pid=fork())<0)
	err_sys("fork error\n");
    else if(pid==0)
	status/=0;
    
    if(wait(&status)!=pid)
	err_sys("wait error\n");
    pr_exit(status);

    exit(0);
}
