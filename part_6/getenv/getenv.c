/*
 * If the name of an existing environment variable is specified as an argument,
 * the function returns a pointer to a string containing the value of this variable.
 * If the variable is not present, NULL is returned.
 */

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv)
{
    char * var;

    if (argc < 2)
    {
        fprintf (stderr, "Too few arguments \n");
        exit (1);
    }

    if ((var = getenv(argv[1])) == NULL)
    {
        printf ("'%s' not found\n", argv[1]);
        exit (1);
    }
    printf ("'%s=%s' found\n", argv[1], var);

    return 0;
}
