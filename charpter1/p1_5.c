#include "../myerr.h"

int main()
{
    int c;
    while((c=getc(stdin))!=EOF)
    {
	if(putc(c,stdout)==EOF)
	    err_sys("output err");
    }
    if(ferror(stdin))
	err_sys("input error");
    return 0;
}
