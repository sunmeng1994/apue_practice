#include"../fuck.h"
static void my1();
static void my2();
int main()
{
    if(atexit(my1)!=0)
	err_sys("can`t register my1");
    if(atexit(my1)!=0)                                                                            
        err_sys("can`t register my1");
    if(atexit(my2)!=0)                                                          
        err_sys("can`t register my2");
    printf("main is done\n");
    exit(0);  
}
static void my1()
{
    printf("fuck1\n");
}
static void my2()
{
    printf("fuck2\n");
}
