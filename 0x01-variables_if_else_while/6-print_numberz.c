#include <stdio.h>
#include <stdlib.h>

/** 
 * main - prints all ths single digit numbers of base 10 with putchar
 *
 * Return: Always 0 (Success)
 */



int main(void)
{
	int num;

	for (num = 0; num < 10; num++)
	{
		putchar(num + '0');
	}
	putchar('\n');
	return (0);
}
