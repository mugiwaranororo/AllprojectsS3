

unsigned long divisor_sum(unsigned long n) {
    if (n == 1) {
        return 0;
    }
    unsigned long sum = 1;
    for (unsigned long i = 2; i*i < n; i++) {
        if (n % i == 0) {
            sum += i;
            sum += n/i;
        }
    }
    return sum;
}