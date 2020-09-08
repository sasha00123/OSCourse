#include <stdio.h>
#include <unistd.h>

int main()
{
    int pid = getpid();

    fork();

    if (getpid() == pid) {
        printf("Hello from parent [PID - %d]\n", pid);
    } else {
        printf("Hello from child [PID - %d]\n", getpid());
    }

    return 0;
}