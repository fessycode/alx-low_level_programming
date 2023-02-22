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
	char alph;

	for (alph = 'a'; alph <= 'z'; alph++)
	{
		if (c == alph)
		{
			_putchar(c + '0');
			return (0);
		}
		else
		{
			return (1);
		}
	}
	return (0);
}
