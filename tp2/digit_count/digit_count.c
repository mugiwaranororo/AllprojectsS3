

unsigned char digit_count(unsigned long n) {
    if (n == 0) {
        return 1;
    }
    unsigned char res = 0;
    while(n >= 1) {
        n /= 10;
        res += 1;
    }
    return res;
}