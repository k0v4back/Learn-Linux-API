#include <stdio.h>
#include <sys/types.h>
#include <sys/time.h>
#include <unistd.h>

int main(void)
{
    fd_set rd_fds;
    fd_set rd_fds_tmp;
    struct timeval tv;
    int i = 0;

    /* Zero rd_set and add input(0) and output(1) descriptors */
    FD_ZERO(&rd_fds);
    FD_SET(0, &rd_fds);
    FD_SET(1, &rd_fds);
    /* Copy rd_fds */
    FD_ZERO(&rd_fds_tmp);
    memcpy(&rd_fds_tmp, &rd_fds, sizeof(rd_fds));

    /* Set timeout */
    tv.tv_sec = 2;
    tv.tv_usec = 0;

    /* Highest-number file descriptor in sets */
    int max_num = 5;

    int ret = select(max_num, &rd_fds, NULL, NULL, &tv);
    if (ret == 0) {
        printf("Timeout\n");
    } else { /* Something happened */
        printf("Data is ready\n");
        printf("FD_ISSET status: %u\n", FD_ISSET(0, &rd_fds));
        
        while (i < max_num) {
            if (FD_ISSET(i, &rd_fds)) {
                char str[1024];
                scanf("%s", str);
                printf("%s", str);
            }
            i++;
        }
        FD_ZERO(&rd_fds);
        memcpy(&rd_fds, &rd_fds_tmp, sizeof(rd_fds_tmp));
    }

    return 0;
}