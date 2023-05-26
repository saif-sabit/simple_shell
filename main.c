#include "shell.h"

/**
 * main - entry point of the simple shell program.
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: Always 0 if success
 */
int main(int argc, char **argv)
{
	char *lineptr;
	size_t size;
	int i;

	(void)argc;
	i = 0;
	signal(SIGINT, _signal);
	while (1)
	{
		i++;
		lineptr = NULL;
		size = 0;
		_prompt(lineptr, size, i, argv);
	}

	return (0);
}
