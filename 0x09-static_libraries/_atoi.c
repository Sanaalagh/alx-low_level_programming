#include "main.h"

int _atoi(char *s)
{
    /* Implement the logic for _atoi function */
    int sign = 1;
    int result = 0;

    if (*s == '-')
    {
        sign = -1;
        s++;
    }

    while (*s)
    {
        if (*s >= '0' && *s <= '9')
        {
            result = result * 10 + (*s - '0');
        }
        else
        {
            break;
        }
        s++;
    }

    return sign * result;
}
