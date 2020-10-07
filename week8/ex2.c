#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    // si and so fields kept being zeroes
    // My best guess is that I have enough RAM to allocate 10MB without using swap.
    // NOTE: The code allocates 1e7 bytes since the task was to allocate 10MB, not 10MiB.

    size_t b10M = 1e7;
    for (int i = 0; i < 10; i++) {
        void *a = malloc(b10M);
        memset(a, 0, b10M);
        sleep(1);
    }
    return 0;
}