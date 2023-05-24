#include "shell.h"

/**
 * _signal_fun - the program in interactive mode.
 * @signal_num: the signal number.
 * Return: void.
 * Description: the program in interactive mode.
 */

void _signal_fun(int signal_num)
{
	(void)signal_num;
	write(STDOUT_FILENO, "\n", 2);
	write(STDOUT_FILENO, "#cisfun$ ", 10);
}
