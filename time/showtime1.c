#include<time.h>
#include<stdio.h>
#include<string.h>
//#include<time.h>
//char*ctime(const time_t*timep);

int main()
{
    time_t t1=time(NULL);
    char*s1=ctime(&t1);
    printf("%s\n",s1);
    printf("%d\n",strlen(s1));
    return 0;
}
