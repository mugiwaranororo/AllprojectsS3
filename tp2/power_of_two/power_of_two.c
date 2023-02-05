

unsigned long power_of_two(unsigned char n) {
    unsigned long i = 1;
    for (unsigned char j = 0; j < n; j++) {
        i *= 2;
    }
    return i;
}