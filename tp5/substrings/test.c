#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <err.h>
#include "substrings.h"

void exit_help()
{
    char help[] =
        "Usage:\n"
        "--split string\n"
        "--merge string1 string2 ...";

    errx(EXIT_FAILURE, "%s", help);
}

void test_substring(int argc, char** argv)
{
    if (argc < 2)
        exit_help();

    substring(argv[1], argv[2]);
}

int main(int argc, char** argv)
{
    if (argc == 1)
        exit_help();

    test_substring(argc, argv);

    return EXIT_SUCCESS;
}