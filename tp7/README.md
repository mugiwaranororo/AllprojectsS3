
# Pointer

## Definition

A pointer is a variable that stores the address of another variable.

Memory addresses are similar to array indexes. They are fixed-length unsigned integers.

Pointers point to memory cells that hold values of specific types.

## Declaration and Initialization

int i = 0x12345678;
int* p = &i;

● i is a variable of type int.
● &i is the address of the variable.
● p is the pointer that holds the address of the variable.
● &i and p are of type int* (pointer to int).