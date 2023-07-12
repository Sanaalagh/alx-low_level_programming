#include "main.h"
#include <stdlib.h>

/**
 * count_words - Counts the number of words in a string.
 * @str: The input string.
 *
 * Return: The number of words.
 */
int count_words(char *str)
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
 * free_words - Frees the allocated memory for words.
 * @words: The array of words.
 * @num_words: The number of words.
 */
void free_words(char **words, int num_words)
{
	int i;

	for (i = 0; i < num_words; i++)
		free(words[i]);

	free(words);
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

	num_words = count_words(str);

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
				free_words(words, j);
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
