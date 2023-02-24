#include"main.h"
#include <stdio.h>

/**
 * int _isupper- checks for uppercase character.
 *
 * @c: the charcter to check
 *
 * Return: return 1 if c is uppercase, otherwise return 0.
 */

int _isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
