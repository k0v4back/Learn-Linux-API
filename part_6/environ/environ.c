/*
 * Reading and writing output of all environment variables
 */

#include <stdio.h>

extern char **environ;

int main(int argc, char **argv)
{
    char **env_point;

    for(env_point = environ; *env_point != NULL; env_point++)
        puts(*env_point);
    
    return  0;
}

