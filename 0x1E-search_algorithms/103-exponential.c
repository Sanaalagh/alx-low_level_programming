#include <stdio.h>

/**
 * exponential_search - Searches for a value in a sorted array of integers
 *                      using the Exponential search algorithm
 * @array: Pointer to the first element of the array
 * @size: Number of elements in array
 * @value: Value to search for
 *
 * Return: Index of the first occurrence of value, or -1 if not found
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t bound;
	size_t left;
	size_t right;
	size_t mid;

    /* Initial checks */
	if (array == NULL || size == 0)
		return (-1);

    /* Finding range for binary search */
	bound = 1;
	while (bound < size && array[bound] < value)
		bound *= 2;

    /* Binary search within the defined range */
	left = bound / 2;
	right = bound < size ? bound : size - 1;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (array[mid] == value)
			return (mid);
		else if (array[mid] < value)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return (-1); /* Value not found */
}
