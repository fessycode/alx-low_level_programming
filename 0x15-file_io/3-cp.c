#include "main.h"
#include <stdio.h>

/**
 * error_file - To checks if files can be opened.
 * @file_from: file from.
 * @file_to: file_to.
 * @argv: arguments.
 * Return: no return.
 */
void error_file(int file_from, int file_to, char *argv[])
{
	if (file_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	if (file_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
}

/**
 * main - To check the code.
 * @argc: number of arguments.
 * @argv: arguments vector.
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	int fil_from, fil_to, err_close;
	ssize_t n_c, n_w;
	char buf[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "%s\n", "Usage: cp file_from file_to");
		exit(97);
	}

	fil_from = open(argv[1], O_RDONLY);
	fil_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);
	error_file(fil_from, fil_to, argv);

	n_c = 1024;
	while (n_c == 1024)
	{
		n_c = read(fil_from, buf, 1024);
		if (n_c == -1)
			error_file(-1, 0, argv);
		n_w = write(fil_to, buf, n_c);
		if (n_w == -1)
			error_file(0, -1, argv);
	}

	err_close = close(fil_from);
	if (err_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fil_from);
		exit(100);
	}

	err_close = close(fil_to);
	if (err_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fil_from);
		exit(100);
	}
	return (0);
}
