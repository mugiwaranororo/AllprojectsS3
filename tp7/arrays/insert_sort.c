#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


#include "insert_sort.h"

int* binsearch(int* begin, int* end, int x)
{
  if(end <= begin)
    return end;
  int lon = end-begin;
  int l = lon/2;
  int* p = begin+l;
  if (*p == x)
    return p;
  if (x<*p)
    return binsearch(begin, p,x);
  return binsearch(p+1, end,x);
}





void array_insert(int *begin, int *end, int x)
{
    int i = 0;
    while (i<end-begin-1 && x<*(end-i-1))
        i++;
    memmove((end-i+1),(end-i),(i+1)*4);
    *(end-i) = x;
}

void array_insert_bin(int* begin, int* end, int x)
{
    int* i = binsearch(begin, end,x);
    memmove(i+1,i,8);
    *i = x;
}





void array_insert_sort(int *begin, int *end)
{
  for(int *i = begin+1; i < end; i++)
  {
    int *j = i-1;
    while (j>=begin && *j>*i)
      j--;
    j++;
    if (*j>*i)
    {
      int temp = *i;
      memmove(j+1,j,(i-j)*4);
      *j = temp;
    }
  }
}

void array_insert_sort_bin(int *begin, int *end)
{
  for(int *i=begin+1; i<end; i++)
  {
    int *j=binsearch(begin,i,*i);
    int temp = *i;
    memmove(j+1,j,(i-j)*4);
    *j = temp;
  }
}
