#include "main.h"


/**
 * print_line - function that draws a straight line
 * @n: is the integer for the paramaters of my function
 * Return: 0
 */

void print_line(int n)
{
	int a;

	for (a = 0; a <= n; a++)
	{
		if (n == 0 && n < 0)
		{
			_putchar('\n');
		}
		else
		{
			_putchar(95);
		}
	}
	_putchar('\n');
}
