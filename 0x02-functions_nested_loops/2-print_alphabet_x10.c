#include "main.h"

/**
 * print_alphabet_x10 - prints 10 times the alphabet, in lowercase
 *
 * Return Always 0
 */

void print_alphabet_x10(void)
{
	char alph;
	int lines;

	for (lines = 1; lines <= 10; lines++)
	{
		for (alph = 'a'; alph <= 'z'; alph++)
		{
			_putchar(alph);
		}
		_putchar(alph);
	}
}
