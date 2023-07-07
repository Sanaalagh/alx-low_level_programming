#include "main.h"

unsigned int _strspn(char *s, char *accept)
{
    /* Implement the logic for _strspn function */
    unsigned int count = 0;
    int found;

    while (*s)
    {
        found = 0;
        for (int i = 0; accept[i]; i++)
        {
            if (*s == accept[i])
            {
                count++;
                found = 1;
                break;
            }
        }

        if (!found)
            break;

        s++;
    }

    return count;
}
