#define _GNU_SOURCE
#include <stdlib.h>
#include <string.h>

void words_free(char** words)
{
    // Frees the strings.
    for (size_t i = 0; words[i]; i++)
        free(words[i]);

    // Frees the string pointers.
    free(words);
}

size_t word(char** pointer, char* s, size_t start) {
    size_t size = 0;
    while (*(s+start+size) != '\0' && *(s+start+size) != ' ') {
        size++;
    }
    char* res = malloc((size+1)*sizeof(char));
    for (size_t i = 0; i!=size; i++) {
        *(res+i) = *(s+start+i);
    }
    *(res+size) = '\0';
    *pointer = res;
    return start+size;
}

char** split(char* s)
{
    size_t size = 1;
    for (size_t i = 0; *(s+i) != '\0'; i++) {
        if (*(s+i) == ' ') {
            size++;
        }
    }
    char** res = malloc((size+1)*sizeof(char*));
    size_t act = 0;
    for (size_t i = 0; i!=size; i++) {
        char* pointer;
        act = word(&pointer,s,act);
        res[i] = pointer;
        act++;
    }
    *(res+size) = NULL;
    return res;
}