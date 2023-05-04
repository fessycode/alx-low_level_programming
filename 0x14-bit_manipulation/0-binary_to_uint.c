#include "main.h"

/**
 * binary_to_uint -To converts a binary number to an unsigned integer.
 * @b: binary.
 *
 * Return: unsigned integer.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int a;
	int l, base_two;

	if (!b)
		return (0);

	a = 0;

	for (l = 0; b[l] != '\0'; l++)
		;

	for (l--, base_two = 1; l >= 0; l--, base_two *= 2)
	{
		if (b[l] != '0' && b[l] != '1')
		{
			return (0);
		}

		if (b[l] & 1)
		{
			a += base_two;
		}
	}

	return (a);
}
