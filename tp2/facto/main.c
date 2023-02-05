#include "facto.h"

#include <stdio.h>

int main() {
    for (int n = 0; n <= 20; n++) {
        unsigned long f = facto(n);
        printf("%d! = %lu\n", n, f);
    }
    return 0;
}