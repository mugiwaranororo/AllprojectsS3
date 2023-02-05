

unsigned long isqrt(unsigned long n) {
    unsigned long res = n;
    while (res*res > n)
    {
        res = res + n/res;
        res = res/2;
    }
    return res;
}