#define _GNU_SOURCE
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

unsigned long* array_fibo(size_t n)
{
    unsigned long *res = malloc(n * sizeof(unsigned long));
    unsigned long u1 = 0;
    unsigned long u2 = 1;
    for (size_t i = 0; i<n; i++) {
        *(res+i) = u1;
        unsigned long u3 = u1;
        u1 = u2;
        u2 += u3;
    }
    return res;
}

char* str_toupper(const char* s)
{
    size_t size = 0;
    while (*(s+size) != '\0') {
        size++;
    }
    char *res = malloc((size+1) * sizeof(char));
    for (size_t i = 0; i < size; i++) {
        *(res+i) = toupper(*(s+i));
    }
    *(res+size) = '\0';
    return res;
}

unsigned char* array_pal_1(unsigned char* a, size_t len)
{
    unsigned char *res = realloc(a,(2*len+1)*sizeof(unsigned char));
    for (size_t i = 0; i!=len; i++) {
        *(res+len+i) = *(res+len-i-1);
    }
    *(res+2*len) = '\0';
    return res;
}

void array_pal_2(unsigned char** a, size_t len)
{
    unsigned char *res = realloc(*a,(2*len+1)*sizeof(unsigned char));
    for (size_t i = 0; i!=len; i++) {
        *(res+len+i) = *(res+len-i-1);
    }
    *(res+2*len) = '\0';
    *a = res;
}

size_t array_min(unsigned char* a, size_t len, unsigned char threshold, unsigned char** result)
{
    unsigned char *temp = malloc((len+1)*sizeof(unsigned char));
    size_t res = 0;
    for (size_t i = 0; i!=len; i++) {
        if (*(a+i) < threshold) {
            *(temp+res) = *(a+i);
            res++;
        }
    }
    *(temp+res) = '\0';
    if (res == 0) {
        *result = NULL;
        free(temp);
        return 0;
    }
    else {
        *result = temp;
        return res;
    }
}

void str_checksum(char** s)
{
    int number = 0;
    size_t size = 0;
    while (*(*s+size) != '\0') {
        number += *(*s+size);
        size++;
    }    
    char *res;
    asprintf(&res,"%s (%X)",*s,number);
    free(*s);
    *s = res;
}