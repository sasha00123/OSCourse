#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/mman.h>


int main() {
    char *str = "This is a nice day";
    int file = open("ex1.txt", O_RDWR);

    ftruncate(file, strlen(str));
    void *virtual_memory = mmap(NULL, strlen(str), PROT_WRITE, MAP_SHARED, file, 0);
    if (virtual_memory == MAP_FAILED) {
        exit(EXIT_FAILURE);
    }

    strcpy(virtual_memory, str);
    munmap(virtual_memory, strlen(str));
    close(file);
    return 0;
}