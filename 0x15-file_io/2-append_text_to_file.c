#include "main.h"

/**
 * append_text_to_file - To appends text at the end of a file
 * @filename: file name.
 * @text_content: content added.
 *
 * Return: 1 if the file exists and -1 if the fails does not exist
 * or if it fails.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int f;
	int n_l;
	int r_w;

	if (!filename)
		return (-1);

	f = open(filename, O_WRONLY | O_APPEND);

	if (f == -1)
		return (-1);

	if (text_content)
	{
		for (n_l = 0; text_content[n_l]; n_l++)
			;

		r_w = write(f, text_content, n_l);

		if (r_w == -1)
			return (-1);
	}

	close(f);

	return (1);
}
