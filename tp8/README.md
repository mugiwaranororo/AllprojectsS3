# Malloc Calloc And Realloc

## Getting Started

### Pointer

if you want to redirect a pointer to another adress you change directly the pointer value

if you want to redirect a pointer to another adress you change directly the pointer valuent to change the value of the pointer you have to use the * operator

### Malloc Calloc And Realloc

malloc is a function that takes a size_t as parameter and returns a void pointer

calloc is a function that takes a size_t and a size_t as parameter and returns a void pointer

realloc is a function that takes a void pointer and a size_t as parameter and returns a void pointer

You can easily use them like this:

```
sub_function(char** malloc_instance, char* string)
{
    *malloc_instance = malloc(sizeof(char) * strlen(string));
    strcpy(*malloc_instance, string);
}

main_function(argv**)
{
    char* malloc_instance = NULL;
    sub_function(&malloc_instance, "Hello World");
    printf("%s\n", malloc_instance);
    free(malloc_instance);
}
```

Here is a good example because the pointer will change its adress