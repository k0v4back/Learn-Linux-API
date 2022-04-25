#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char *env_args[]  = {"NAME=value", "SOME=else", (char *)NULL};
    char *filename = argv[0];
    char *args;

    if(argc != 2 || strcmp(argv[1], "--help") == 0)
        perror("pathname");

    args = strrchr(argv[1], '/');
    if(args != NULL)
        args++;
    else
        args = argv[1];

    execle(argv[1], args, "hello world", "goodbye", (char *) NULL, env_args);
    perror("This line should never get printed\n");

    return 0;
}
