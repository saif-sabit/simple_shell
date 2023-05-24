#include "shell.h"

/**
 * _getline - get a line from a stream.
 * @lineptr: the line.
 * @n: the size of the line.
 * @stream: the stream.
 * Return: the number of bytes read.
 */
int _getline(char **lineptr, size_t *n, FILE *stream)
{
	static char *line;
	int bytes_read;
	int fd;

	if (stream == stdin)
		fd = STDIN_FILENO;
	else
		return (-1);
	if (lineptr == NULL || n == NULL)
		return (-1);

	line = malloc(BUFFER_SIZE);
	if (line == NULL)
		return (-1);

	bytes_read = read(fd, line, BUFFER_SIZE);
	if (bytes_read < 0)
	{
		free(line);
		return (-1);
	}

	*lineptr = malloc(bytes_read);
	if (lineptr == NULL)
	{
		free(line);
		return (-1);
	}
	*lineptr[bytes_read] = '\n';

	_strcpy(*lineptr, line);
	return (0);
}
