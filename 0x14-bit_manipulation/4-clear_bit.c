#include "main.h"

/**
 * clear_bit - sets the value of a bit to 0 at a given index.
 * @n: pointer of an unsigned long integer.
 * @index: index.
 *
 * Return: 1 for success and  -1 for failure
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned int id;

	if (index > 63)
		return (-1);

	id = 1 << index;

	if (*n & id)
		*n ^= id;

	return (1);
}
