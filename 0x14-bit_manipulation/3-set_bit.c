#include "main.h"

/**
 * set_bit - To sets the value of a bit to 1 at a given index.
 * @n: pointer of an unsigned long integer.
 * @index: inde.
 *
 * Return: 1 for success and  -1 for fail.
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned int id;

	if (index > 63)
		return (-1);

	id = 1 << index;
	*n = (*n | id);

	return (1);
}
