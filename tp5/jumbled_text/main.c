#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <err.h>
#include "jumbled_text.h"

void exit_help()
{
    char help[] =
        "Usage:\n"
        "--split string\n"
        "--merge string1 string2 ...";

    errx(EXIT_FAILURE, "%s", help);
}

void test_mix(int argc, char** argv)
{
    if (argc != 2)
        exit_help();


    mix(argv[1]);
}

int main(int argc, char** argv)
{
    if (argc == 1)
        exit_help();

    test_mix(argc, argv);

    return EXIT_SUCCESS;
}