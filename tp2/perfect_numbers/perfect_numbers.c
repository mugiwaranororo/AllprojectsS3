#include "perfect_numbers.h"
#include "divisor_sum.h"

int is_perfect_number(unsigned long n) {
    return divisor_sum(n) == n;
}