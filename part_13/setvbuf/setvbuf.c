/*
 * setvnuf() allows you to select the type of buffering that will be applied library stdio.
 * setbuf() is built on top of setvbuf () and does exactly the same task
 */

#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 1024

int main(void)
{
    static char buf[BUF_SIZE];

    if(setvbuf(stdout, buf, _IOFBF, BUF_SIZE) != 0)
    {
        fprintf(stderr, "Couldn't set buffer");
        exit(EXIT_FAILURE);
    }

    return 0;
}
