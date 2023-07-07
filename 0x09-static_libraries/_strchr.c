#include "main.h"

char *_strchr(char *s, char c)
{
    /* Implement the logic for _strchr function */
    while (*s)
    {
        if (*s == c)
            return s;
        s++;
    }

    if (*s == c)
        return s;

    return NULL;
}
