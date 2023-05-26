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
	int counts;

	(void)argc;
	counts = 0;
	signal(SIGINT, _signal_ignore);
	while (1)
	{
		counts++;
		lineptr = NULL;
		size = 0;
		_prompt(lineptr, size, counts, argv);
	}

	return (0);
}
