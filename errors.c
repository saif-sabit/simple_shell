#include "shell.h"

/**
 * error - print the error message.
 * @status: the status of the error.
 * @s: the string to print.
 * @k: the number of the error.
 */
void error(int status, char **s, int k)
{
	char *progname = program();
	char errun[MAX_NUM];

	_itoa(k, errun);
	write(STDOUT_FILENO, progname, _strlen(progname));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, errun, _strlen(errun));
	write(STDOUT_FILENO, ": ", 2);

	if (status == 1)
	{
		perror(*s);
	}
	else if (status == 2)
	{
		char exit_err[] = "exit: Illegal number: ";

		write(STDOUT_FILENO, exit_err, _strlen(exit_err));
		write(STDOUT_FILENO, s[1], _strlen(s[1]));
		write(STDOUT_FILENO, "\n", 1);
	}
	free(progname);
}
