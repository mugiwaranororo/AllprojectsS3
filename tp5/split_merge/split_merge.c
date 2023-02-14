#include <stddef.h>
#include "split_merge.h"

void split(char s[], char words[][MAX_CHAR])
{
    int count = 0;
    size_t act = 0;
    for (size_t i = 0; s[i] != '\0'; i++) {
        if (s[i] == ' ') {
            words[count][act] = '\0';
            act = 0;
            count += 1;
        }
        else {
            words[count][act] = s[i];
            act += 1;
        }
    }
    words[count][act] = '\0';
    words[count+1][0] = '\0';
}

void merge(char s[], size_t argc, char** argv)
{
    size_t count = 2;
    size_t size = 0;
    while (count != argc) {
        for (size_t i = 0; argv[count][i] != '\0'; i++) {
            s[size] = argv[count][i];
            size += 1;
        }
        count += 1;
    }
    s[size] = '\0';
}