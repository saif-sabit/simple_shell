#include "shell.h"

/**
 * _signal_fun - the signal function.
 * @signal_num: the signal number.
 * Return: void.
 * Description: the program in interactive mode.
 * Reference: https://www.youtube.com/watch?v=Ig4e0PTeJH4
 */

void _signal_fun(int signal_num)
{
	(void)signal_num;
	write(STDOUT_FILENO, "\n", 2);
	write(STDOUT_FILENO, "#cisfun$ ", 10);
}
