#include<sys/stat.h>
#include<fcntl.h>
#define BUF_SIZE 1024
int main(int argc,char**argv)
{
    int inputFd,outputFd,openFlags;
    mode_t filePerms;
    int numRead;
    char buf[BUF_SIZE];
    if(argc!=3||strcmp(argv[1],"--help")==0)
    {
	printf("%s old-file new-file\n",argv[0]);
	return 1;
    }
    inputFd=open(argv[1],O_RDONLY);
    if(inputFd==-1)
    {
	printf("open file failed %s\n",argv[1]);
	return 1;
    }
    openFlags=O_CREAT|O_WRONLY|O_TRUNC;
    filePerms=S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH;
    
    outputFd=open(argv[2],openFlags,filePerms);
    if(outputFd==-1)
	printf("open file %s faild\n",argv[2]);
    
    while((numRead=read(inputFd,buf,BUF_SIZE))>0)
    {
	if(write(outputFd,buf,numRead)!=numRead)
	    printf("couldn`t write whole buffer");
    }
    
    if(numRead==-1)
    {
	printf("read failed\n");
	return 1;
    }
    
    if(close(inputFd)==-1)
	printf("close input");
    if(close(outputFd==-1))
	printf("close output");
    return 0;
}
