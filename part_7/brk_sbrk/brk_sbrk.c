#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{
    char *p = (char *)sbrk(0);

    if(brk(p + 23) < 0) 
    {
        fprintf(stderr, "brk() error!");
        exit(1);
    }

    return 0;
}
