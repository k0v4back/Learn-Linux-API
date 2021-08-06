/*
 * getgrgid() return info about group by group ID
 */

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <grp.h>

int main(void)
{
    unsigned gid;
    struct group * user_group;

    puts("Enter GID:");
    scanf("%u", &gid);

    user_group = getgrgid(gid);
    if(!user_group)
    {
        fprintf(stderr, "Incorrect GID \n");
        exit(1);
    }

    puts("---------RESULT INFO ABOUT GROUP----------");
    printf("gr_name: %s \n", user_group->gr_name);
    printf("gr_passwd: %s \n", user_group->gr_passwd);
    printf("gr_gid: %u \n", user_group->gr_gid);

    return 0;
} 
