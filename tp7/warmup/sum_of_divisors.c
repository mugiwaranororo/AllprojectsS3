# include <stdio.h>

unsigned long sum_of_divisors(unsigned long n, size_t *count)
{
    *count = 1;
    unsigned long res = 1;
    for (unsigned long i = 2; i*i <= n; i++) {
        if (n % i == 0) {
            if (i*i != n) {
                res += i;
                *count += 1;
            }
            *count += 1;
            res += n/i;
        }
    }
    return res;
}

int main()
{
    unsigned long x;
    unsigned long sum;
    size_t count;

    x = 28;
    sum = sum_of_divisors(x, &count);
    printf("x = %lu\n", x);
    printf("sum   = %lu\n", sum);
    printf("count = %zu\n\n", count);

    x = 100;
    sum = sum_of_divisors(x, &count);
    printf("x = %lu\n", x);
    printf("sum   = %lu\n", sum);
    printf("count = %zu\n", count);
}