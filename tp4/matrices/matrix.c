#include <stdio.h>

void print_matrix(char s[], double m[], size_t rows, size_t cols)
{
    for (size_t i = 0; s[i] != '\0'; i++)
        printf("%c", s[i]);
    printf(" =\n");
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
            printf("%4g ", m[i * cols + j]);
        printf("\n");
    }
    printf("\n");
}

void transpose(double m[], size_t rows, size_t cols, double r[])
{
    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < cols; j++)
            r[j * rows + i] = m[i * cols + j];
}

void add(double m1[], double m2[], size_t rows, size_t cols, double r[])
{
    for (size_t i = 0; i<rows; i++) {
        for (size_t j = 0; j<cols; j++) {
            r[i*cols+j] = m1[i*cols+j]+m2[i*cols+j];
        }
    }
}

void mul(double m1[], double m2[], size_t r1, size_t c1, size_t c2, double r[])
{
    for (size_t i = 0; i<r1; i++) {
        for (size_t j = 0; j<c2; j++) {
            double res = 0;
            for (size_t resj = 0; resj<c1; resj++)
            {
                res += m1[i*c1+resj]*m2[resj*c2+j];
            }
            r[i*c2+j] = res;
        }
    }
}