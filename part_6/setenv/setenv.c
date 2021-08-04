/*
 * Add a new variable or an existing one to the environment
 */

#include <stdio.h>
#include <stdlib.h>

#define FL_OVWER 0 /* Overwrite flag */
#define FL_NO_OVWER_IF_EXIST 1 /* Not overwrit of exit */

int main (int argc, char ** argv)
{
    if (argc < 3)
    {
        fprintf(stderr, "Too few arguments \n");
        exit(1);
    }

    if (setenv(argv[1], argv[2], FL_OVWER) != 0)
    {
        fprintf(stderr, "Cann't set %s \n", argv[1]);
        exit(1);
    }

    printf ("%s=%s\n", argv[1], getenv (argv[1]));
    
    return 0;
}
