#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * count_words - Counts the number of words in a string
 * @str: The string to count words in
 *
 * Return: The number of words
 */
int count_words(char *str)
{
    int count = 0;
    int i = 0;

    while (str[i] != '\0')
    {
        if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
            count++;
        i++;
    }

    return count;
}

/**
 * extract_word - Extracts a word from a string
 * @str: The string to extract the word from
 * @start: The starting index of the word
 * @end: The ending index of the word
 *
 * Return: The extracted word as a newly allocated string
 */
char *extract_word(char *str, int start, int end)
{
    int i, j;
    char *word;

    word = malloc((end - start + 2) * sizeof(char));
    if (word == NULL)
        return NULL;

    for (i = start, j = 0; i <= end; i++, j++)
        word[j] = str[i];
    word[j] = '\0';

    return word;
}

/**
 * strtow - Splits a string into words
 * @str: The string to split
 *
 * Return: An array of strings (words)
 */
char **strtow(char *str)
{
    int total_words, i, j, k, start, end;
    char **words;

    if (str == NULL || *str == '\0')
        return NULL;

    total_words = count_words(str);
    if (total_words == 0)
        return NULL;

    words = malloc((total_words + 1) * sizeof(char *));
    if (words == NULL)
        return NULL;

    for (i = 0, j = 0; str[i] != '\0'; i++)
    {
        if (str[i] != ' ')
        {
            start = i;
            while (str[i] != ' ' && str[i] != '\0')
                i++;
            end = i - 1;

            words[j] = extract_word(str, start, end);
            if (words[j] == NULL)
            {
                for (k = 0; k < j; k++)
                    free(words[k]);
                free(words);
                return (NULL);
            }

            j++;
        }
    }

    words[j] = NULL;

    return (words);
}
