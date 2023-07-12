#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * count_words - Counts the number of words in a string.
 * @str: The input string.
 *
 * Return: The number of words.
 */
int count_words(char *str)
{
	int count = 0;
	int i = 0;

	while (str[i] != '\0')
	{
		/* Skip leading spaces */
		while (str[i] == ' ')
			i++;

		if (str[i] != '\0')
		{
			count++;
			/* Move to the end of the current word */
			while (str[i] != ' ' && str[i] != '\0')
				i++;
		}
	}

	return (count);
}

/**
 * strtow - Splits a string into words.
 * @str: The input string.
 *
 * Return: A pointer to an array of strings (words), or NULL on failure.
 */
char **strtow(char *str)
{
	char **words;
	int num_words;
	int i, j, k;
	int word_start, word_end;

	if (str == NULL || *str == '\0')
		return (NULL);

	num_words = count_words(str);

	words = malloc((num_words + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);

	i = 0;
	j = 0;
	while (str[i] != '\0' && j < num_words)
	{
		/* Skip leading spaces */
		while (str[i] == ' ')
			i++;

		/* Find the start and end of the current word */
		word_start = i;
		while (str[i] != ' ' && str[i] != '\0')
			i++;
		word_end = i - 1;

		/* Allocate memory for the current word */
		words[j] = malloc((word_end - word_start + 2) * sizeof(char));
		if (words[j] == NULL)
		{
			for (k = 0; k < j; k++)
				free(words[k]);
			free(words);
			return (NULL);
		}

		/* Copy the characters of the current word */
		for (k = 0; k <= word_end - word_start; k++)
			words[j][k] = str[word_start + k];
		words[j][k] = '\0';

		j++;
	}

	words[j] = NULL;

	return (words);
}
