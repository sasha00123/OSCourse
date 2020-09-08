#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "unistd.h"

int main() {

    while (1) {
        size_t max_size = 1000;
        char *line = malloc(sizeof(char) * max_size);


        printf("[%d] > ", getpid());
        getline(&line, &max_size, stdin);
        if (line[0] == '\n') {
            continue;
        }

        char **argv = malloc(sizeof(char *) * max_size);
        for (int i = 0; i < max_size; i++) {
            argv[i] = malloc(sizeof(char) * max_size);
        }
        {
            int i = 0;
            do {
                char *arg = strtok((i == 0 ? line : NULL), " \n");
                if (arg) {
                    strcpy(argv[i], arg);
                } else {
                    argv[i] = 0;
                }
                i++;
            } while (argv[i - 1]);

            if (strcmp(argv[0], "exit") == 0) {
                break;
            }
        }

        int pid = getpid();
        fork();
        if (getpid() != pid) {
            execvp(argv[0], argv);
            exit(0);
        } else {
            usleep(100000);
        }
    }
    return 0;
}
