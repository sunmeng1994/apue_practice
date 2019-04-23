#include<fcntl.h>
#include<myerr.h>
void testlseek()
{
    if(lseek(STDIN_FILENO,0,SEEK_CUR)==-1)
	printf("cannot seek\n");
    else
	printf("seek ok\n");
}
void creatEmpty()
{
    char buf1[]="abcdefghij";
    char buf2[]="ABCDEFGHIJ";

    int fd=creat("file.hole",FILE_MODE);
    if(fd<0)
	err_sys("creat error");
    
    if(write(fd,buf1,10)!=10)
	err_sys("buf1 write error");
    
    if(lseek(fd,16384,SEEK_SET)==-1)
	err_sys("lseek error");

    if(write(fd,buf2,10)!=10)
	err_sys("buf2 write error");
}
int main()
{
   //testlseek();
    creatEmpty();
    return 0;
}
