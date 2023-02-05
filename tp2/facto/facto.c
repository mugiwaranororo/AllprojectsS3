

unsigned long facto(unsigned long n) {
    if (n == 0) {
        return 1;
    }
    else {
        return n*facto(n-1);
    }
}