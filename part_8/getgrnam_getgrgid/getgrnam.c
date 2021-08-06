/*
 * getgrnam() return info about group by group name
 */

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <grp.h>

int main(void)
{
    char group_name[20];
    struct group * user_group;

    puts("Enter group name:");
    scanf("%s", group_name);

    user_group = getgrnam(group_name);
    if(!user_group)
    {
        fprintf(stderr, "Incorrect group name");
        exit(1);
    }

    puts("---------RESULT INFO ABOUT GROUP----------");
    printf("gr_name: %s \n", user_group->gr_name);
    printf("gr_passwd: %s \n", user_group->gr_passwd);
    printf("gr_gid: %u \n", user_group->gr_gid);

    return 0;
} 
