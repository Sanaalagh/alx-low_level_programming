#include "main.h"

int _strlen(char *s)
{
    /* Implement the logic for _strlen function */
    int len = 0;
    while (*s)
    {
        len++;
        s++;
    }
    return len;
}
