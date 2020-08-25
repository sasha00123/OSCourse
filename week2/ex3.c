#include <stdio.h>

int main() {
    int n;
    printf("Enter figure size: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int l = n - i, r = n + i;
        for (int j = 1; j < 2 * n; j++) {
            if (l <= j && j <= r) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}