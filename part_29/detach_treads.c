#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <pthread.h>

void* thread_func(void* arg) {
    int i;

    for (i = 0; i < 5; i++) {
        sleep(1);
        printf("pthread id=%ld iteration i=%d\n", pthread_self(), i);
    }

    return NULL;
}

int main(int argc, char* argv[]) {
    int i;
    int N = 5;
    pthread_t thread1, thread2, thread3;
    pthread_t threads[N];
    int result;

    /* Create threads */
    for (i = 0; i < N; i++) {
        result = pthread_create(&threads[i], NULL, thread_func, NULL);
        if (result != 0) {
            perror("Creating the first thread");
            return EXIT_FAILURE;
        } else {
            pthread_detach(threads[i]);
        }
    }

    /* Threads will run until the process ends */
    
    sleep(N * 2);
    printf("Done!");

    return 0;
}