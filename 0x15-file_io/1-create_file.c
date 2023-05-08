#include "main.h"

/**
 * create_file - To creates a file
 * @filename: file name.
 * @text_content: content written in the file.
 *
 * Return: 1 if it success and  -1 if it fails.
 */
int create_file(const char *filename, char *text_content)
{
	int f;
	int n_l;
	int r_w;

	if (!filename)
		return (-1);

	f = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	if (f == -1)
		return (-1);

	if (!text_content)
		text_content = "";

	for (n_l = 0; text_content[n_l]; n_l++)
		;

	r_w = write(f, text_content, n_l);

	if (r_w == -1)
		return (-1);

	close(f);

	return (1);
}
