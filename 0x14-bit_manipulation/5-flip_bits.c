#include "main.h"

/**
 * flip_bits - Rturns the num of bits to flip to get from one num to another
 * @n: num1.
 * @m: num2.
 *
 * Return: num.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int num_bits;

	for (num_bits = 0; n || m; n >>= 1, m >>= 1)
	{
		if ((n & 1) != (m & 1))
			num_bits++;
	}

	return (num_bits);
}
