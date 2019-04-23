#include<myerr.h>
#include<fcntl.h>
#define MAXSIZE 4096

int main()
{
    int n;
    char buf[MAXSIZE];
    int fd=open("fuck.txt",O_RDONLY);
    if(fd<0)
    {
	write(STDOUT_FILENO,"fuckingOpenError",16);
    }
    else
    {
	write(STDOUT_FILENO,"OPENFUCKING",11);
    }
    while((n=read(fd,buf,4096))>0)
    {
	if(write(STDOUT_FILENO,buf,n)!=n)
	    err_sys("write err");
    }
    if(n<0)
	err_sys("read error");
    return 0;
}
