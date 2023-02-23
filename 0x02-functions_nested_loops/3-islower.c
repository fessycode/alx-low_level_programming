#include "main.h"

/**
 * _islower - checks for lowercase character
 *
 * @c: character to check
 *
 * Return: return 0 if c is is lowercase and 1 otherwise
 */


int _islower(int c)
{
	if (c >= 97 && c <= 122)
	{
		return (1);
	}
	else
	{
		return (0);
	}
	_putchar('\n');

}
