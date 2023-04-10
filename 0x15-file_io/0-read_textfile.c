#include "main.h"
/*
 * read_textfile - a function that reads a textfile and prints
 * @filename: filename to read and print.
 * @letters: numbers of letters to be printed.
 *
 * Return: numbers of letters printed. It fails, returns 0.
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int n;
	ssize_t nrd, nwr;
	char *buffer;

	if (filename == NULL)
		return (0);
	n = open(filename, O_RDONLY);

	if (n == -1)
		return (0);
	buffer = malloc(sizeof(char) * (letters));
	if (buffer == NULL)
		return (0);
	nrd = read(n, buffer, letters);
	nrw = write(STDOUT_FILENO, buffer, nrd);

	close(n);

	free(buffer);

	return (nwr);
}
