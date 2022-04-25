/*
 * execve() loads a new program into the process memory. During this
 * operation, the old program is deleted along with the stack, data
 * and heap and replaced with similar parts of the new program.
 */

#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    char *nargv[] = {argv[1], "parm1", "parm2", "parm3", (char *)NULL};
    char *nenv[]  = {"NAME=value", (char *)0};

     printf("this is the original program\n");

     execve(argv[1], nargv, nenv);

     perror("This line should never get printed\n");

     return 0;
}
