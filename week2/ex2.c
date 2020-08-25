#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    printf("Enter string: ");
    scanf("%1000s", s);

    // Well, unfortunately, Linux doesn't have built-in strrev.
    // Let's do some magic here
    size_t n = strlen(s);
    for (int i = 0; i < n / 2; i++) {
        char t = s[i];
        s[i] = s[n - i - 1];
        s[n - i - 1] = t;
    }

    printf("The reverse is: %s", s);
}
