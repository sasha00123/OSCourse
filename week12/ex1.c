#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main() {
    int rnd = open("/dev/random", O_RDONLY);
    unsigned short rndInts[21];
    read(rnd, rndInts, sizeof rndInts);
    char rndString[21];
    for (int i = 0; i < 20; i++) {
        rndString[i] = rndInts[i] % 26 + 'a';
    }
    rndString[20] = 0;
    printf("%s", rndString);
}