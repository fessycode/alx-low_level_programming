#include "main.h"

/**
 * clear_bit - sets the value of a bit to 0 at a given index.
 * @n: pointer of an unsigned long int.
 * @index: index of the bit.
 *
 * Return: 1 if it worked, -1 if fail.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned int pr;

	if (index > 63)
		return (-1);

	pr = 1 << index;

	if (*n & pr)
		*n ^= pr;
	return (1);
}
