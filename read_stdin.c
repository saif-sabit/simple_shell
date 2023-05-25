#include "shell.h"

/**
 * read_stdin - read from stdin.
 * Return: lineptr.
 */
char *read_stdin(void)
{
	char *lineptr = NULL;
	size_t n = 0;
	int len;

	len = getline(&lineptr, &n, stdin);
	if (len == EOF)
	{
		write(STDOUT_FILENO, "\n", 1);
		free(lineptr);
		exit(EXIT_SUCCESS);
	}
	if (len == -1)
	{
		perror("getline: ");
		free(lineptr);
		exit(EXIT_FAILURE);
	}

	if (space_check(lineptr) == 1)
	{
		free(lineptr);
		return (NULL);
	}

	return (lineptr);
}
