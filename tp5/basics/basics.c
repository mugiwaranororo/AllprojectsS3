#include <stddef.h>

size_t str_chr(char s[], char c)
{
    size_t i = 0;
    while (s[i] != '\0')
    {
        if (s[i] == c)
        {
            return i;
        }
        i++;
    }
    return i;

}

void str_cat(char s1[], char s2[])
{
    size_t len1 = 0;
    while (s1[len1] != '\0')
    {
        len1++;
    }
    size_t len2 = 0;
    while (s2[len2] != '\0')
    {
        s1[len1 + len2] = s2[len2];
        len2++;
    }
    s1[len1+len2] = '\0';
}

int str_cmp(char s1[], char s2[])
{
    size_t i = 0;
    while (s1[i] != '\0')
    {
        if (s2[i] == '\0')
        {
            return 1;
        }
        if (s1[i] < s2[i])
        {
            return -1;
        }
        if (s1[i] > s2[i])
        {
            return 1;
        }
        i++;
    }
    if (s2[i] == '\0')
    {
        return 0;
    }
    return -1;
}

unsigned int str_toui(char s[])
{
    unsigned int res = s[0] - '0';
    for (size_t i = 1; s[i] != '\0'; i++)
    {
        res *= 10;
        res += s[i] - '0';
    }
    return res;
}

void rm_chr(char c, char s[])
{
    size_t i = 0;
    size_t count = 0;
    while (s[i] != '\0')
    {
        if (s[i] == c) {
            count++;
        }
        else {
            s[i - count] = s[i];
        }
        i++;
    }
    s[i - count] = '\0';
}