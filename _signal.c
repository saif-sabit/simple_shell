#include "shell.h"

/**
 * _exit_shell - exits the shell on getline error or Ctrl + D (EOF condition)
 * @lineptr: string input from user
 *
 * Return: void
 */
void _exit_shell(char *lineptr)
{
	free(lineptr);
	exit(EXIT_SUCCESS);
}


/**
 * _signal - function that ignores ^C (SIGINT) to the process
 * @sig: integer value of signal
 *
 * Return: Nothing
 */

void _signal(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n$ ", 3);
}
