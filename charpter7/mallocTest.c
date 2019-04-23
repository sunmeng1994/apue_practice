#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#define ONE_G 1024*1024
#define ONE_M 1024

int mallocOneM()
{
    char*a=NULL;
    a=(char*)malloc(1024*1024*sizeof(char));
    if(a==NULL)
    {
	perror("malloc error");
	return -1;
    }
    char*startPointer=a;
    int i;
    for(i=0;i<1024*1024;i++)
    {
	*a=i%128+1;
	a++;
    }
    char*readPointer=startPointer;
    for(i=0;i<1024*1024;i++)
    {
	int charnum=*readPointer;
	printf("%d %d %d\n",readPointer,i,charnum);
	readPointer+=10000;
	i+=10000;
    }
    printf("start sleep now\n");
    sleep(10);
    free(startPointer);
    printf("free now\n");
}

int main()
{
    mallocOneM();
    return 0;
}
