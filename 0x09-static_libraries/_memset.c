#include "main.h"

char *_memset(char *s, char b, unsigned int n)
{
    /* Implement the logic for _memset function */
    char *start = s;

    while (n > 0)
    {
        *s = b;
        s++;
        n--;
    }

    return start;
}
