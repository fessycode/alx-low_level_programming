#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints the alphabet in lowercase
 *
 * Return: Always 0 (Success)
 *
 */

int main(void)
{
	char str = 'a';

	for (str = 'a'; str <= 'z'; str++)
		putchar(str);
	putchar('\n');
	return (0);
}
