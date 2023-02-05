#include "fibo.h"

#include <stdio.h>

int main() {
    for (int n = 0; n <= 90; n++) {
        unsigned long f = fibo(n);
        printf("(%d) = %lu\n", n, f);
    }
    return 0;
}