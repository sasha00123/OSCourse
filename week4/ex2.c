#include "stdlib.h"
#include "stdio.h"
#include "unistd.h"
#include "string.h"

int main(int argc, char *argv[]) {
    long n = strtol(argv[1], NULL, 10);

    printf("Forking %ld times\n", n);

    for (int i = 0; i < n; i++) {
        fork();
    }
    sleep(5);
    return 0;
}