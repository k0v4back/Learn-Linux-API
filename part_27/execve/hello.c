#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    printf("HELLO\n");

    for(int i = 1; i < argc; i++){
        printf("argv[%d] = %s\n", i, argv[i]);
    }

    printf("env NAME  = %s\n", getenv("NAME"));

    return 0;
}
