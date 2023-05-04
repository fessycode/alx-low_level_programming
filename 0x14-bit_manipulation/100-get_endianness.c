#include "main.h"

/**
 * get_endianness - To checks the endianness
 *
 * Return: 0 if big endian, 1 if little endian
 */
int get_endianness(void)
{
	unsigned int end;
	char *n;

	end = 1;
	n  = (char *) &end;

	return ((int)*n);
}
