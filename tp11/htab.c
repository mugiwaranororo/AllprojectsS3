#include <err.h>
#include <string.h>
#include <stdint.h>
#include <stdio.h>

#include "htab.h"

uint32_t hash(char *key)
{
    size_t i = 0;
    uint32_t hash = 0;
    while (*(key+i) != '\0') {
        hash += key[i++];
        hash += hash << 10;
        hash ^= hash >> 6;
    }
    hash += hash << 3;
    hash ^= hash >> 11;
    hash += hash << 15;
    return hash;
}

struct htab *htab_new()
{
    struct htab *htab = malloc(sizeof(struct htab));
    if (htab == NULL) {
        errx(EXIT_FAILURE, "%s", "Not enough memory");
    }
    htab->capacity = 4;
    htab->size = 0;
    htab->data = malloc(htab->capacity*sizeof(struct pair*));
    for (size_t i = 0; i<htab->capacity; i++) {
        struct pair *sentinel = calloc(1, sizeof(struct pair));
        sentinel->key = "0";
        sentinel->hkey = 0;
        sentinel->value = NULL;
        sentinel->next = NULL;
        *(htab->data+i) = *sentinel;
    }
    return htab;
}

void htab_clear(struct htab *ht)
{
    for (size_t i = 0; i<ht->capacity; i++) {
        struct pair *pair = ht->data+i;
        pair = pair->next;
        while (pair != NULL) {
            struct pair *next = pair->next;
            free(pair);
            pair = next;
        }
    }
    ht->size = 0;
}

void htab_free(struct htab *ht)
{
    htab_clear(ht);
    free(ht->data);
    free(ht);
}

struct pair *htab_get(struct htab *ht, char *key)
{
    for (size_t i = 0; i<ht->capacity; i++) {
        struct pair *pair = ht->data+i;
        pair = pair->next;
        while (pair != NULL) {
            if (pair->key == key) {
                return pair;
            }
            pair = pair->next;
        }
    }
    return NULL;
 }

 struct pair *replace_htab(struct htab *ht) {
    struct pair *list = malloc(ht->capacity*sizeof(struct pair));
    ht->size = 0;
    for (size_t i = 0; i<ht->capacity; i++) {
        struct pair *sentinel = calloc(1, sizeof(struct pair));
        sentinel->hkey = 0;
        sentinel->key = "0";
        sentinel->value = NULL;
        sentinel->next = NULL;
        *(list+i) = *sentinel;
    }
    for (size_t i = 0; i<ht->capacity/2; i++) {
        struct pair *pair = ht->data+i;
        pair = pair->next;
        while (pair != NULL) {
            struct pair *next = pair->next;
            pair->next = NULL;
            size_t place = pair->hkey % ht->capacity;
            struct pair *sentinel = list+place;
            if (sentinel->next == NULL) {
                ht->size++;
            }
            struct pair *prev;
            while (sentinel != NULL) {
                prev = sentinel;
                sentinel = sentinel->next;
            }
            prev->next = pair;
            pair = next;
        }
    }
    return list;
 }

int htab_insert(struct htab *ht, char *key, void *value)
{
    if (htab_get(ht, key) == NULL) {
        if (ht->size*4>=ht->capacity*3) {
            ht->capacity*=2;
            struct pair *replace = replace_htab(ht);
            free(ht->data);
            ht->data = replace;
            if (ht->data == NULL) {
                errx(EXIT_FAILURE, "%s", "Not enough memory");
            }
        }
        struct pair *temp = calloc(1, sizeof(struct pair));
        temp->key = key;
        temp->value = value;
        temp->next = NULL;
        temp->hkey = hash(key);
        size_t place = temp->hkey % ht->capacity;
        struct pair *sentinel = ht->data+place;
        if (sentinel->next == NULL) {
            ht->size++;
        }
        struct pair *prev;
        while (sentinel != NULL) {
            prev = sentinel;
            sentinel = sentinel->next;
        }
        prev->next = temp;
        return 1;
    }
    return 0;
}

void htab_remove(struct htab *ht, char *key)
{
    for (size_t i = 0; i<ht->capacity; i++) {
        struct pair *sentinel = ht->data+i;
        struct pair *prev = sentinel;
        sentinel = sentinel->next;
        while (sentinel != NULL && sentinel->key != key) {
            prev = sentinel;
            sentinel = sentinel->next;
        }
        if (sentinel != NULL) {
            free(sentinel);
            prev->next = sentinel->next;
        }
    }
}

void print_hash(struct htab *hash) {
    printf("capacity = %ld ",hash->capacity);
    printf("size = %ld\n",hash->size);
    for (size_t i = 0; i<hash->capacity; i++) {
        struct pair *pair = hash->data+i;
        pair = pair->next;
        while (pair != NULL) {
            printf(" %s ",pair->key);
            pair = pair->next;
        }
        printf("\n");
    }
}

int main() {
    return 1;
}