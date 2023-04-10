#include "main.h"


/**
 * append_text_to_file - appends text at the end of a file
 * @filename: filename.
 * @text_content: conten to write  in the file.
 *
 * Return: 1 if it success. -1 if it fails.
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int n;
	int L;
	int rwr;

	if (filename == NULL)
		return (-1);
	n = open(filename, O_CREAT | O_APPEND);
	if (n == -1)
		return (-1);
	if (text_content)
	{
		for (L = 0; text_content[L];  L++)
			;
		rwr = write(n, text_content, L);
		if (rwr == -1)
			return (-1);
	}
	close(n);

	return (1);

}
