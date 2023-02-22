#include "main.h"


/**
 * print_alphabet - print the alphabet in lowercase
 *
 * Return: 0
 */

void print_alphabet(void)
{
	char alph;

	for (alph = 'a'; alph <= 'z'; alph++)
	{
		_putchar(alph);
	}
	_putchar('\n');
}
