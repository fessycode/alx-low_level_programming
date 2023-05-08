#include "main.h"

/**
 * read_textfile - Read text files  and prints the letters
 * @filename: file name
 * @letters: numbers of letters printed.
 *
 * Return: numbers of letters printed and 0 when It failed.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int f;
	ssize_t n_r, n_w;
	char *b;

	if (!filename)
		return (0);

	f = open(filename, O_RDONLY);

	if (f == -1)
		return (0);

	b = malloc(sizeof(char) * (letters));
	if (!b)
		return (0);

	n_r = read(f, b, letters);
	n_w = write(STDOUT_FILENO, b, n_r);

	close(f);

	free(b);

	return (n_w);
}
