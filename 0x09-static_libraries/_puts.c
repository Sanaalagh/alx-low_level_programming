#include "main.h"

void _puts(char *s)
{
    /* Implement the logic for _puts function */
    while (*s)
    {
        _putchar(*s);
        s++;
    }
    _putchar('\n');
}
