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
		if (n > 0)
		{
			_putchar(95);
		}
		else
		{
			_putchar('\n');
		}
	}
	_putchar('\n');
}
