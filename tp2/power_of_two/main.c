#include "power_of_two.h"

#include <stdio.h>

int main() {
    for (unsigned char n = 0; n <= 63; n++) {
        unsigned long f = power_of_two(n);
        printf("power_of_two(%d): %lu\n", n, f);
    }
}