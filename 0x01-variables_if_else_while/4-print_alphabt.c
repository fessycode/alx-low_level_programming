#include <stdio.h>
#include <stdlib.h>

/**
 * main - Prints the alphabet except q and e
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	char alph;

	for (alph = 'a'; alph <= 'z'; alph++)
	{
		if (alph != 'q' && alph != 'e')
			putchar(alph);
	}
	putchar('\n');
	return (0);
}
