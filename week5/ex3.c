#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

pthread_t prod_thread, cons_thread;

int producer_alive = 1, consumer_alive;

int bs = 0;
const int LIMIT = 1e2;
int iteration_producer = 0, iteration_consumer = 0;

void cond_wait(int *cond) {
    while (!*cond) {
        usleep(100);
    }
}

void cond_signal(int *cond) {
    *cond = 1;
}

void *produce() {
    while (1) {
        if (iteration_producer % 1000 == 0) {
            printf("Producer: %d\n", iteration_producer);
        }
        if (bs == LIMIT || !producer_alive) {
            producer_alive = 0;
            cond_wait(&producer_alive);
        }
        bs++;
        if (bs == 1) {
            cond_signal(&consumer_alive);
        }
        iteration_producer++;
    }
}

void *consume() {
    while (1) {
        if (iteration_consumer % 1000 == 0) {
            printf("Consumer: %d\n", iteration_consumer);
        }
        if (bs == 0 || !consumer_alive) {
            consumer_alive = 0;
            cond_wait(&consumer_alive);
        }
        bs--;
        if (bs == LIMIT - 1) {
            cond_signal(&producer_alive);
        }
        iteration_consumer++;
    }
}

int main() {
    pthread_create(&prod_thread, NULL, produce, NULL);
    pthread_create(&cons_thread, NULL, consume, NULL);
    pthread_join(prod_thread, NULL);
    pthread_join(cons_thread, NULL);

    return 0;
}
