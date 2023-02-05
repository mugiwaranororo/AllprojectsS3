#include "divisor_sum.h"

#include <stdio.h>
#include <err.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    if (argc != 2) {
        errx(1,"Error: 2 arguments required, %d given", argc);
    }
    unsigned long param = strtoul(argv[1], NULL, 10);
    if (param == 0) {
        errx(1,"Error: invalid argument");
    }
    unsigned long result = divisor_sum(param);
    printf("divisor_sum(%lu) = %lu\n", param, result);
    return 0;
}