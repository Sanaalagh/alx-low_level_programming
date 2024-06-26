#include <stdio.h>
#include <math.h>
#include "search_algos.h"

/**
 * jump_list - Searches for a value in a sorted list of integers
 *             using the Jump search algorithm
 * @list: Pointer to the head of the list to search in
 * @size: Number of nodes in list
 * @value: Value to search for
 *
 * Return: Pointer to the first node where value is located,
 * or NULL if not found
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t step = sqrt(size);
	listint_t *current = list, *prev = NULL;
	size_t i;

	if (list == NULL)
		return (NULL);

	while (current && current->n < value)
	{
		prev = current;
		for (i = 0; current->next && i < step; i++)
			current = current->next;
		printf("Value checked at index [%lu] = [%d]\n", current->index, current->n);
	}

	printf("Value found between indexes [%lu] and [%lu]\n",
			prev->index, current->index);

	current = prev;
	while (current && current->n < value)
	{
		printf("Value checked at index [%lu] = [%d]\n", current->index, current->n);
		current = current->next;
		if (!current)
			return (NULL);
	}

	if (current->n == value)
		return (current);

	return (NULL);
}
