#include <stdio.h>
#include "pascal.h"

// Prints Pascal's Triangle.
// tr: triangle to print
// len: length of the triangle.
void print_triangle(unsigned int tr[][MAX_LEN], size_t len)
{
    for (size_t row = 0; row < len; row++)
    {
        for (size_t col = 0; col < len; col++)
            if (tr[row][col] != 0)
                printf("%5u ", tr[row][col]);

        printf("\n");
    }
}

// Generates Pascal's Triangle.
// tr: triangle to generate.
// len: length of the triangle.
void pascal_triangle(unsigned int tr[][MAX_LEN], size_t len)
{
    for (size_t i = 0;i < len; i++) {
        tr[i][0] = 1;
        tr[i][i] = 1;
    }
    for (size_t i = 1; i < len; i++) {
        size_t stop = 1;
        while (stop <= i) {
            tr[i+1][stop] = tr[i][stop-1]+tr[i][stop];
            stop++;
        }
    }
}