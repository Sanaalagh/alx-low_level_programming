#include "main.h"
#include <stdlib.h>

/**
 * mem_clear - Clears the memory of a string array.
 * @s: The string array.
 */
void mem_clear(char **s)
{
	int i;

	for (i = 0; s[i] != NULL; i++)
		free(s[i]);

	free(s);
}

/**
 * word_count - Counts the number of words in a string.
 * @str: The input string.
 *
 * Return: The number of words.
 */
int word_count(char *str)
{
	int count = 0;
	int in_word = 0;
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			in_word = 0;
		else if (in_word == 0)
		{
			in_word = 1;
			count++;
		}

		i++;
	}

	return (count);
}

/**
 * strtow - Splits a string into words.
 * @str: The input string.
 *
 * Return: A pointer to an array of words, or NULL on failure.
 */
char **strtow(char *str)
{
	char **words;
	int num_words;
	int word_start = 0;
	int word_end;
	int word_len;
	int i, j;

	if (str == NULL || *str == '\0')
		return (NULL);

	num_words = word_count(str);

	words = malloc((num_words + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);

	for (i = 0, j = 0; str[i] != '\0' && j < num_words; i++)
	{
		if (str[i] != ' ')
		{
			word_start = i;
			word_end = i;
			while (str[word_end] != ' ' && str[word_end] != '\0')
				word_end++;

			word_len = word_end - word_start;
			words[j] = malloc((word_len + 1) * sizeof(char));
			if (words[j] == NULL)
			{
				mem_clear(words);
				return (NULL);
			}

			for (i = 0; i < word_len; i++)
				words[j][i] = str[word_start++];

			words[j][i] = '\0';
			j++;
		}
	}

	words[j] = NULL;

	return (words);
}
