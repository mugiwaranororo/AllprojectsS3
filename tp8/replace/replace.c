#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char* replace(const char* s, const char* from, const char* to)
{
    size_t size_from = strlen(from);
    size_t size_to = strlen(to);
    int occ = 0;
    size_t size = strlen(s);
    char* pointer  = strstr(s, from);

    while (pointer != NULL) {
        occ++;
        pointer++;
        pointer = strstr(pointer, from);
    }

    size_t size_final = size+(occ*(size_to-size_from));
    char* res = calloc(size_final+1,sizeof(char));
    size_t resi = 0;
    size_t replacei = 0;
    pointer = strstr(s, from);

    while (pointer != NULL) {
        if (replacei+s == pointer) {
            for (size_t i = 0; i!=size_to; i++) {
                *(res+resi) = *(to+i);
                resi++;
            }
            replacei += size_from;
            pointer += 1;
            pointer = strstr(pointer,from);
        }
        else {
            *(res+resi) = *(s+replacei);
            resi++;
            replacei++;
        }
    }
    while (*(replacei+s) != '\0') {
        *(resi+res) = *(replacei+s);
        resi++;
        replacei++;
    }
    return res;
}