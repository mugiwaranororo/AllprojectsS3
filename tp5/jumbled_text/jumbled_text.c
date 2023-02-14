#include "jumbled_text.h"
#include <stdio.h>

int separator(char s) {
    if (s == ' ' || s == ',' || s == ';' || s == ':' || s == '!' || s == '?' || s == '.' || s == '/' || s == '%' || s == '*' || s == '$' || s == '=' || s == '+' || s == ')' || s == '@' || s == '_' || s == '-' || s == '(' || s == '&') {
        return 1;
    }
    else {
        if (s > '1' && s < '9') {
            return 1;
        }
    }
    return 0;
}

void mix(char s[]) {
    size_t i = 0;
    int firstletter = 1;
    while (s[i] != '\0') {
    if (separator(s[i])) {
        printf("%c",s[i]);
        i += 1;
        firstletter = 1;
    }
    else {
            if (firstletter) {
                printf("%c",s[i]);
                i += 1;
                firstletter = 0;
            }
            else {
                if (s[i+1] != '\0' && !separator(s[i+1])) {
                    if (s[i+2] != '\0' && !separator(s[i+2])) {
                        printf("%c",s[i+1]);
                        printf("%c",s[i]);
                        i += 2;
                    }
                    else {
                        printf("%c",s[i]);
                        i += 1;
                    }
                }
                else {
                    printf("%c",s[i]);
                    i += 1;
                }
            }
        }
    }
    printf("\n");
}