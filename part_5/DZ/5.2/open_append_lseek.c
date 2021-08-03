/*
 * Write a program that opens and existing file for writing with the
 * O_APPEND flag, and then seeks to the beginning of the file before
 * writing some data.  Where does the data appear in the file?  Why?
 *
 * ANSWWER: Due to the fact that the O_APPEND flag is used,
 * writing to the file occurs atomically and lseek does not matter
 */

#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#define STRING_PATTERN "Using linux API"

int main(int argc, char *argv[])
{
    int fd;
    off_t ret;
    ssize_t write_bytes;
    
    /* check count of arguments */
    if(argc != 2){
        fprintf(stderr, "Couldn't name of file as 1 argument \n");
        exit(1);
    }

    /* open file from arguments */
    fd = open(argv[1], O_WRONLY | O_APPEND);
    if(fd < 0){
        fprintf(stderr, "Couldn't open %s file \n", argv[1]);
        exit(1);
    }

    /* make offset */
    ret = lseek(fd, (off_t)0, SEEK_SET);
    if(ret == (off_t)-1){
        fprintf(stderr, "Couldn't offset \n");
        exit(1);
    }

    /* write data to open file */
    write_bytes = write(fd, STRING_PATTERN, strlen(STRING_PATTERN));
    if(write_bytes < 0){
        fprintf(stderr, "Couldn't write data to file %s\n", argv[1]);
        exit(1);
    }

    close(fd);

    return 0;
}
