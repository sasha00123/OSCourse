#include <stdio.h>
#include <unistd.h>

int main(void) {
    printf("Hello");
//    printf("Hello\n");
    fork();
    printf("\n");
    return 0;
}
