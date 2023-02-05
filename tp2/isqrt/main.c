#include "isqrt.h"

#include <stdio.h>

int main() {
    for (int n = 0; n <= 200; n+=8) {
        unsigned long f = isqrt(n);
        printf("isqrt(%d) = %lu\n", n, f);
    }
    return 0;
}