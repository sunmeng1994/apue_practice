#include<unistd.h>
#include<stdio.h>
static void charatatime(char*str)
{
    char*ptr;
    int c;
    setbuf(stdout,NULL);
    for(ptr=str;*ptr!=0;ptr++)
    {
	c=*ptr;
	putc(c,stdout);
    }
}

int main()
{
    pid_t pid;
    if((pid=fork())<0)
    {
	printf("fork error\n");
    }
    else if(pid==0)
    {
	charatatime("out put from child");
    }
    else
    {
	charatatime("out put from parents");
    }
    return 0;
}
