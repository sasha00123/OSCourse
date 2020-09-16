#include <stdio.h>
#include <unistd.h>
#include <pthread.h>


int finished;
void *print_name(void *vargp) {
    int pid = *(int *) vargp;
    printf("Entered thread: %d\n", pid);

    printf("Exited thread: %d\n", pid);
    finished = 1;
    return NULL;
}

int main() {

    pthread_t tid;
    for (int i = 0; i < 3; i++) {
        printf("Created thread: %d\n", i);
        finished = 0;
        pthread_create(&tid, NULL, print_name, (void *) &i);
        while (!finished) {
            sleep(1);
        }
    }

    return 0;
}