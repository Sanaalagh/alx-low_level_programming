#include "main.h"

char *_strstr(char *haystack, char *needle)
{
    /* Implement the logic for _strstr function */
    while (*haystack)
    {
        char *h = haystack;
        char *n = needle;

        while (*haystack && *n && *haystack == *n)
