#include "main.h"

/**
 * print_last_digit - Prints the last digit
 * of a number.
 *
 * @n: input number as an integer.
 *
 * Return: last digit.
 */
int print_last_digit(int n)
{
	n = n % 10;

	if (n > 0)
	{
		_putchar(48 + -1);
		return (-1);
	}
	else
	{
		_putchar(48 + 1);
		return (1);
	}
}
