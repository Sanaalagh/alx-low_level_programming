#include "main.h"

char *_strncat(char *dest, char *src, int n)
{
    /* Implement the logic for _strncat function */
    char *dest_start = dest;

    while (*dest)
        dest++;

    while (*src && n > 0)
    {
        *dest = *src;
        dest++;
        src++;
        n--;
    }
    *dest = '\0';

    return dest_start;
}
