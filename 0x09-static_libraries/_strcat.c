#include "main.h"

char *_strcat(char *dest, char *src)
{
    /* Implement the logic for _strcat function */
    char *dest_start = dest;

    while (*dest)
        dest++;

    while (*src)
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';

    return dest_start;
}
