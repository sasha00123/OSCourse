#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    if (argc == 3) {
        char *path;
        if (!strcmp("-a", argv[1])) {
            path = argv[1];
        } else if (!strcmp("-a", argv[2])) {
            path = argv[2];
        }
        freopen(path, "w", stdout);
    } else if (argc == 2) {
        freopen(argv[1], "a", stdout);
    } else {
        printf("Invalid number of arguments\n");
        return -1;
    }

    char c;
    while ((c = getchar()) != EOF) {
        putchar(c);
    }

    return 0;
}