#include "stdio.h"
#include "limits.h"
#include "float.h"

int main() {
    int x = INT_MAX;
    float y = FLT_MAX;
    double z = DBL_MAX;

    printf("%lu, %d\n", sizeof x, x);
    printf("%lu, %f\n", sizeof y, y);
    printf("%lu, %f\n", sizeof z, z);
};