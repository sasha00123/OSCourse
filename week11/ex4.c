#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>

int main() {
    int source = open("ex1.txt", O_RDWR);
    int dest = open("ex1.memcpy.txt", O_RDWR);

    struct stat srcstat = {};
    if (fstat(source, &srcstat)) { exit(EXIT_FAILURE); };

    ftruncate(dest, srcstat.st_size);
    void *source_virtual_memory = mmap(NULL, srcstat.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, source, 0),
            *dest_virtual_memory = mmap(NULL, srcstat.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, dest, 0);

    strcpy(dest_virtual_memory, source_virtual_memory);

    munmap(source_virtual_memory, srcstat.st_size);
    munmap(dest_virtual_memory, srcstat.st_size);

    close(source);
    close(dest);
}