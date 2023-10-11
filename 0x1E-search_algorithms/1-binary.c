#include "search_algos.h"

/**
 * print_array - to output a list of array.
 * @array: Being the array to be printed.
 * @left: Being the left index to start from.
 * @right: Being the right index to start from.
 */
void print_array(int *array, size_t left, size_t right)
{
	size_t i;

	if (array == NULL)
		return;

	printf("Searching in array: ");

	for (i = left; i <= right; i++)
	{
		printf("%d", array[i]);
		if (i != right)
			printf(", ");
		else
			printf("\n");
	}
}

/**
 * binary_search - To searches for a value in a sorted array of
 * integers using the Binary search algorithm.
 * @array: being a sorted array of integers.
 * @size: Being the size of the array.
 * @value: Being the value to be searched for in the array.
 * Return: The index where value is located or -1 if array
 * is NULL or value cannot be found within the array.
 */
int binary_search(int *array, size_t size, int value)
{
	size_t left, right, mid;

	if (array == NULL)
		return (-1);

	left = 0;
	right = size - 1;

	while (left <= right)
	{
		print_array(array, left, right);

		mid = (left + right) / 2;
		if (array[mid] < value)
			left = mid + 1;
		else if (array[mid] > value)
			right = mid - 1;
		else if (array[mid] == value)
			return (mid);
	}
	return (-1);
}
