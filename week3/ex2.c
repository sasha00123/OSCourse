#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int n, int a[]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (a[j] > a[j + 1]) {
                // Swapping magic
                a[j] = a[j] ^ a[j + 1];
                a[j + 1] = a[j] ^ a[j + 1];
                a[j] = a[j] ^ a[j + 1];
            }
        }
    }
}

int main() {
    srand(31415);

    const int N = 10;

    int a[N];
    for (int i = 0; i < 10; i++) {
        a[i] = rand() % 100;
    }

    printf("Initial array:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    bubble_sort(N, a);

    printf("Sorted array:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}