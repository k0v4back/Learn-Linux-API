#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define STRING_WRITE "TEST"

int main(void)
{
    FILE * fp;
    unsigned max_write = strlen(STRING_WRITE);
    char buf[max_write + 1];

    fp = fopen ("test.txt", "w");
    if(fp < 0){
        if(errno == EINVAL)
            perror("Invalid value in flags");
        exit(1);        
    }

    for(int i = 0; i < 5; i++){
        fwrite(buf, sizeof(char), max_write, fp);
        fflush(fp);
    }

    fclose(fp);


    return 0;
}
