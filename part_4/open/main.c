/*
 * An example of opening with 'flags' and 'mode', also for error checking
 */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
    int fd;
    
    fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU | S_IRGRP | S_IWGRP | S_IROTH);
    if(fd < 0){
        if(errno == EINVAL)
            perror("Invalid value in flags");
        exit(1);        
    }
    
    return 0;
}
