#include "shell.h"

/**
 * _errors - print the error message.
 * @status: the status of the error.
 * @s: the string to print.
 * @k: the number of the error.
 * Return: void.
 * Description: function that print the error message in the shell.
 * It is used to print the error message in the non-interactive mode.
 * It is used in non-interactive mode.
 */
void _errors(int status, char **s, int k)
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
