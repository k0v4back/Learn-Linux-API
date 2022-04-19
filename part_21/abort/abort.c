/*
 * abort() terminates the calling process with a SIGABRT signal.
 * The default action for a SIGABRT signal is to create a core dump file and terminate process.
 */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp = fopen("test.txt", "w");
    if(!fp){
        perror("open");
        abort();
    }

    fclose(fp);
    printf("End of programm\n");

    return 0;
}

