#include "main.h"

char *_strcpy(char *dest, char *src)
{
    /* Implement the logic for _strcpy function */
    char *dest_start = dest;
    while (*src)
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return dest_start;
}

