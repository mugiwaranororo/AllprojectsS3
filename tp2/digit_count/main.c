#include "digit_count.h"

#include <stdio.h>

int main() {
    unsigned long ii = 0;
    for (unsigned char i = 0;i<=64;i++) {
        unsigned char c = digit_count(ii);
        printf("digit_count(%lu) = %d\n",ii,c);
        if (ii == 0) {
            ii++;
        }
        else {
            ii *= 2;
        }
    }
    return 0;
}