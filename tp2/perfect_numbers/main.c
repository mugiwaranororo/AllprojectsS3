#include "perfect_numbers.h"

#include <stdio.h>

int main() {
    for (unsigned long i = 1; i <= 100000; i++) {
        if (is_perfect_number(i)) {
            printf("%lu\n", i);
        }
    }
}