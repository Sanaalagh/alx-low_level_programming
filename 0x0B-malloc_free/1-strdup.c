#include "main.h"
#include <stdlib.h>

/**
 * _strdup-Returns a pointer to a newly allocated space in memory,
 * containing a copy of the string given as a parameter.
 * @str: The string to duplicate;
 * Return:A pointer to the duplicated string;
 * or NULL if insufficient memory was available.
 */
char *_strdup(char *str)
{
	char *dup;
	unsigned int len = 0, i;

	if (str == NULL)
		return (NULL);

	while (str[len] != '\0')
		len++;

	dup = malloc((len + 1) * sizeof(char));

	if (dup == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
		dup[i] = str[i];

	return (dup);
}
