#include "main.h"

char *_strncpy(char *dest, char *src, int n)
{
    /* Implement the logic for _strncpy function */
    char *dest_start = dest;

    while (*src && n > 0)
    {
        *dest = *src;
        dest++;
        src++;
        n--;
    }

    while (n > 0)
    {
        *dest = '\0';
        dest++;
        n--;
    }

    return dest_start;
}
