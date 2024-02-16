#include <stdio.h>
#include <poll.h>
#include <unistd.h>

#define TIMEOUT 5

int main(void)
{
    struct pollfd fds[2];

    /* Input descriptor and input events */
    fds[0].fd = 0;
    fds[0].events = POLLIN;

    /* Output descriptor and output events */
    fds[1].fd = 1;
    fds[1].events = POLLOUT;

    int ret = poll(fds, 1, TIMEOUT * 1000);
    if (!ret) {
        printf("Timeout");
    } else { /* Something happened */
        /* Check input descriptor */
        if (fds[0].revents & POLLIN) {
            char str[1024];
            scanf("%s", str);
            printf("%s", str);
        }
        /* Check output descriptor */
        if (fds[0].revents & POLLOUT) {
            printf("Output is writable\n");
        }
    }

    return 0;
}