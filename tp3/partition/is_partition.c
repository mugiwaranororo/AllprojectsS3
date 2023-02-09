#include <stddef.h>

int __is_partition(unsigned char a[],size_t len, unsigned char pivot, size_t i)
{
    size_t j = 0;
    while (j < i)
    {
        if (a[j] > pivot)
            return 0;
        j++;
    }
    while (j < len)
    {
        if (a[j] < pivot)
            return 0;
        j++;
    }
    return 1;
}


long is_partition(unsigned char a[], size_t len, unsigned char pivot)
{
    for (size_t i = 0; i < len; i++)
    {
        if (a[i] == pivot)
        {
            int res = __is_partition(a, len, pivot, i);
            if (res == 1)
                return i;
        }
    }
    return -1;
}