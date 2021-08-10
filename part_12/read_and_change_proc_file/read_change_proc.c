/*
 * Read and change /proc file. Read and output info file /proc/sys/kernel/pid_max
 * If you want to update file you must be root user
*/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_LINE 100

int main(int argc, char ** argv)
{
    int fd;
    char line[MAX_LINE];
    ssize_t num_characters;

    fd = open("/proc/sys/kernel/pid_max", (argc > 1) ? O_RDWR : O_RDONLY);
    if(fd == -1)
    {
        fprintf(stderr, "Couldn't open file \n");
        exit(EXIT_FAILURE);
    }

    /* read data from fd */
    num_characters = read(fd, line, MAX_LINE);
    if(num_characters == -1)
    {
        fprintf(stderr, "Couldn't read data \n");
        exit(EXIT_FAILURE);
    }
    
    if(argc > 1)
        printf("Old value: ");
    printf("%.*s", (int) num_characters, line);

    /* write data to fd if argc > 1 */
    if(argc > 1)
    {
        if(write(fd, argv[1], strlen(argv[1])) != strlen(argv[1]))
        {
            fprintf(stderr, "Not all characters are written");
            exit(EXIT_FAILURE);
        }
        system("echo /proc/sys/kernel/pid_max now contains ");
        system("cat /proc/sys/kernel/pid_max");
    }

    return 0;
}


