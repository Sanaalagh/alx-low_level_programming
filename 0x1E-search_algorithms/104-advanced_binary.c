#include <stdio.h>

/**
 * advanced_binary - Searches for a value in a sorted array of integers
 *                    using the Advanced Binary search algorithm
 * @array: Pointer to the first element of the array
 * @size: Number of elements in array
 * @value: Value to search for
 *
 * Return: Index of the first occurrence of value, or -1 if not found
 */
int advanced_binary(int *array, size_t size, int value)
{
	size_t low = 0, high = size - 1, mid;
	int found = -1;
	size_t i; /* Move the declaration here */

	if (array == NULL)
		return (-1);

	while (low <= high)
	{
		printf("Searching in array: ");
		for (i = low; i <= high; i++) /* Use the previously declared variable i */
		{
			printf("%d", array[i]);
			if (i < high)
				printf(", ");
			else
				printf("\n");
		}

		mid = (low + high) / 2;
		if (array[mid] == value)
		{
			found = mid;
			high = mid - 1;
		}
		else if (array[mid] < value)
			low = mid + 1;
		else
			high = mid - 1;
	}

	return (found);
}
