#include "main.h"

char *_strpbrk(char *s, char *accept)
{
    /* Implement the logic for _strpbrk function */
    while (*s)
    {
        for (int i = 0; accept[i]; i++)
        {
            if (*s == accept[i])
                return s;
        }
        s++;
    }

    return NULL;
}
