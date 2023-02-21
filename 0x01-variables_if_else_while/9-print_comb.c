#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints all possible combination of single digit numbers.
 *
 * Return: Always 0 (Success)
 */


int main(void)
{
	int num;

	for (num = 0; num <= 9; num++)
	{
		putchar(num + '0');
		putchar(',');
		putchar(' ');
	}
	putchar('\n');
	return (0);
}
