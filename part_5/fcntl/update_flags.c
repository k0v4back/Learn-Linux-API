/*
 * Update file descriptor
 */

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define FILE "test.txt"

int main(void)
{
   int fd;
   int flags;

   fd = open(FILE, O_WRONLY | O_CREAT | O_TRUNC,
           S_IWUSR | S_IRUSR | S_IWGRP | S_IRGRP | S_IROTH);
   if(fd < 0){
       fprintf(stderr, "Couldn't open %s\n", FILE);
       exit(1);
   }

   flags = fcntl(fd, F_GETFL);
   if(flags < 0){
       fprintf(stderr, "Couldn't get file flags\n");
       exit(1);
   }

   /* check O_APPEND flag befor update*/
   if(flags & O_APPEND)
       puts("O_APPEND is in the flags");
   else
       puts("O_APPEND is not in the flags");

   flags |= O_APPEND;
   if((fcntl(fd, F_SETFL, flags) < 0)){
       fprintf(stderr, "Couldn't set new file flags\n");
       exit(1);
   }

   /* check O_APPEND flag befor update*/
   if(flags & O_APPEND)
       puts("O_APPEND is in the flags");
   else
       puts("O_APPEND is not in the flags");


   return 0;
}


