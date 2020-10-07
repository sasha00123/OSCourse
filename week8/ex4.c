#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>

int main() {
    size_t b10M = 1e7;
    for (int i = 0; i < 10; i++) {
        void *a = malloc(b10M);
        memset(a, 0, b10M);
        struct rusage *usage = malloc(sizeof(struct rusage));
        getrusage(RUSAGE_SELF, usage);
        printf("ru_maxrss: %ld\n", usage->ru_maxrss);
        sleep(1);
    }
    return 0;
}