#include "shell.h"

/**
 * read_line - read a line from stdin.
 * Return: the line.
 * Description: function that reads a line from stdin and returns it.
 * it's used in non-interactive mode
 */
char *read_line(void)
{
	char *lineptr = NULL;
	size_t n = 0;
	int len;

	len = getline(&lineptr, &n, stdin);
	if (len == EOF)
	{
		free(lineptr);
		exit(EXIT_FAILURE);
	}
	if (len == -1)
	{
		perror("getline: ");
		exit(EXIT_FAILURE);
	}
	return (lineptr);
}
