Copy code
#include "main.h"
#include <stddef.h>

/**
 * rev_string - Reverses a string
 * @s: The string to be reversed
 */
void rev_string(char *s)
{
	if (s == NULL)
		return;

	int length = 0;
	char *start = s;
	char *end = s;
	char temp;

	while (*end != '\0')
	{
		end++;
		length++;
	}

	end--;

	while (start < end)
	{
		temp = *start;
		*start = *end;
		*end = temp;

		start++;
		end--;
	}
}
