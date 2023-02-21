#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints the lowercase alphabet in reverse
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	char alph;

	for (alph = 'z'; alph >= 'a'; alph--)
	{
		putchar(alph);
	}
	putchar('\n');
	return (0);

}
