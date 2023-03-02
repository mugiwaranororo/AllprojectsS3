#include <stdlib.h>
#include <stdio.h>
#include "list.h"


void list_init(struct list *list)
{
    list = malloc(sizeof(struct list));
    list->next = NULL;
}

int list_is_empty(struct list *list)
{
    return list->next == NULL;
}

size_t list_len(struct list *list)
{
    size_t len = 0;
    for (struct list *l = list; l->next; l = l->next) {
        len++;
    }
    return len;
}

void list_push_front(struct list *list, struct list *elm)
{
    struct list *prev = list->next;
    list->next = elm;
    elm->next = prev;
}

struct list *list_pop_front(struct list *list)
{
    struct list *prev = list;
    list = list->next;
    struct list *act = list;
    prev->next = list->next;
    return act;
}

struct list *list_find(struct list *list, int value)
{
    struct list *l = list;
    while (l != NULL && l->data != value) {
        l = l->next;
    }
    return l;
}

struct list *list_lower_bound(struct list *list, int value)
{
    struct list *prev = list;
    list = list->next;
    while (list != NULL && list->data <= value ) {
        prev = list;
        list = list->next;
    }
    return prev;
}

int list_is_sorted(struct list *list)
{
    for (struct list *l1 = list->next; l1 != NULL; l1 = l1->next) {
        for (struct list *l2 = l1; l2 != NULL; l2 = l2->next) {
            if (l1->data > l2->data) {
                return 0;
            }
        }
    }
    return 1;
}

void list_insert(struct list *list, struct list *elm)
{
    struct list *l = list;
    while (l->next != NULL && l->next->data < elm->data) {
        l = l->next;
    }
    elm->next = l->next;
    l->next = elm;
}

void list_rev(struct list *list)
{
    struct list *cur = list->next;
    struct list *prev = list;
    struct list *prev2 = NULL;
    while (cur != NULL) {
        prev = cur;
        cur = cur->next;
        prev->next = prev2;
        prev2 = prev;
    }
    list->next = prev;
}
void list_half_split(struct list *list, struct list *second)
{
    size_t len = list_len(list);
    struct list *l = list->next;
    struct list *prev = list;
    for (size_t i = 0; i < len/2; i++) {
        prev = l;
        l = l->next;
    }
    prev->next = NULL;
    second->next = l;
}

void print_list(struct list *list)
{
    printf("list_is_empty() = %s\n", list_is_empty(list) ? "yes" :  "no");
    printf("list_is_sorted() = %s\n", list_is_sorted(list) ? "yes" :  "no");
    printf("list_len() = %zu\n", list_len(list));

    int line = 1;

    printf("[");
    if (list->next)
    {
        goto pastfst;
        while (list->next)
        {
            line += printf(";");

            if (line > 72)
            {
                printf("\n ");
                line = 1;
            }

            pastfst:
            line += printf(" %2d", list->next->data);
            list = list->next;
        }
    }

    printf(" ]\n");
}

int main() {
    struct list l6 = {NULL, 4 };
    struct list l5 = { NULL, 12 };
    struct list l4 = { &l5, 10 };
    struct list l3 = { &l4, 6 };
    struct list l2 = { &l3, 5 };
    struct list l1 = { &l2, 3 };
    struct list sentinel = { &l1, 0 };
    struct list sentinel2 = {NULL, 0};
    struct list elements[10];
    struct list *list = &sentinel;
    struct list *list2 = &sentinel2;
    list_init(list);
    list_init(list2);
    list_rev(list);
    list_half_split(list, list2);
    print_list(list2);
    print_list(list);
}