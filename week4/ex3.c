#include "stdlib.h"
#include "stdio.h"
#include "string.h"

int main() {

    while (1) {
        char *command = malloc(sizeof(char) * 1000);
        printf("> ");
        scanf("%1000s", command);
        if (strcmp(command, "exit") == 0) {
            break;
        }
        system(command);
        free(command);
    }
    return 0;
}