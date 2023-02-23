#include "main.h"

/**
 * times_table - Prints the 9 times table
 *
 * Return: no return
 */
void times_table(void)
{
	int x, y, res;
	
	for (x = 0; x <= 9; x++)
	{
		_putchar(48);
		for (y = 1; y <=9; y++)
		{
			res = x * y;
			_putchar(44);
			_putchar(32);
			if (res <= 9)
			{
				_putchar(32);
				_putchar(res + 48);
			}
			else
			{
				_putchar((res / 10) + 48);
				_putchar((res % 10) + 48);
			}
		}
		_putchar('\n')
	}
}
