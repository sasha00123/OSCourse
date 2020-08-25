#include <stdio.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int main() {
    int a, b;
    printf("Enter first number (a): ");
    scanf("%d", &a);

    printf("Enter second number (b): ");
    scanf("%d", &b);

    swap(&a, &b);

    printf("Swapped numbers: a = %d, b = %d", a, b);
    return 0;
}