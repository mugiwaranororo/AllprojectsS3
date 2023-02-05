

unsigned long fibo(int n) {
    unsigned long n1 = 0;
    unsigned long n2 = 1;
    for (int i = 0; i < n; i++) {
        unsigned long tmp = n1;
        n1 = n2;
        n2 = tmp + n2;
    }
    return n1;
}