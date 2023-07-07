#include "main.h"

char *_memcpy(char *dest, char *src, unsigned int n)
{
    /* Implement the logic for _memcpy function */
    char *dest_start = dest;

    while (n > 0)
    {
        *dest = *src;
        dest++;
        src++;
        n--;
    }

    return dest_start;
}
