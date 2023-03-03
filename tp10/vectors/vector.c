#include <err.h>
#include <stdio.h>
#include "vector.h"

struct vector *vector_new()
{
    struct vector *v = malloc(sizeof(struct vector));
    if (v == NULL) {
        errx(EXIT_FAILURE, "%s", "Not enough memory");
    }
    v->capacity = 1;
    v->size = 0;
    v->data = malloc(sizeof(int));
    if (v->data == NULL) {
        errx(EXIT_FAILURE, "%s", "Not enough memory");
    }
    return v;

}

void vector_free(struct vector *v)
{
    free(v->data);
    free(v);
}

void double_capacity(struct vector *v)
{
    v->capacity *= 2;
    v->data = realloc(v->data, sizeof(int)*v->capacity);
    if (v->data == NULL) {
        errx(EXIT_FAILURE, "%s", "Not enough memory");
    }
}

void vector_push(struct vector *v, int x)
{
    if (v->size == v->capacity) {
        double_capacity(v);
    }
    *(v->size+v->data) = x;
    v->size += 1;
}

int vector_pop(struct vector *v, int *x)
{
    if (v->data == NULL) {
        return 0;
    }
    v->size -= 1;
    *x = *(v->data+v->size);
    return 1;
}

int vector_get(struct vector *v, size_t i, int *x)
{
    if (i >= v->size) {
        return 0;
    }
    else {
        *x = *(v->data+i);
        return 1;
    }
}

void vector_insert(struct vector *v, size_t i, int x)
{
    if (i>=0 && i<= v->size) {
        if (v->capacity == v->size) {
            double_capacity(v);
        }
        int temp = x;
        while (i <= v->size) {
            temp = *(v->data+i);
            *(v->data+i) = x;
            x = temp;
            i++;
        }
        v->size++;
    }
}

int vector_remove(struct vector *v, size_t i, int *x)
{
    if (i>=0 && i< v->size) {
        *x = *(v->data+i);
        while (i < v->size-1) {
            *(v->data+i) = *(v->data+i+1);
            i++;
        }
        v->size--;
        return 1;
    }
    return 0;
}

void print_vector(struct vector *v) {
    printf("capacity = %ld\n",v->capacity);
    printf("size = %ld\n", v->size);
    for (size_t i = 0; i<v->size; i++) {
        printf("el%ld = %d\n",i ,*(v->data+i));
    }
}

int main() {
    return 1;
}