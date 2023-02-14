#include "substrings.h"
#include <stdio.h>

void substring(char s[], char search[]) {
    printf("%s\n",s);
    int res = 0;
    size_t i = 0;
    size_t count = 0;
    while (s[i] != '\0' && search[count] != '\0') {
        if (s[i] == search[count]) {
            if (count == 0) {
                res = i;
            }
            count += 1;
        }
        else {
            count = 0;
            if (s[i] == search[count]) {
                res = i;
                count += 1;
            }
        }
        i += 1;
    }
    if (search[count] == '\0') {
        for (int j = 0; j != res; j++) {
            printf(" ");
        }
        printf("^\n");
    }
    else {
        printf("Not Found!\n");
    }
}