#include "shell.h"
/**
 * main - the main function.
 * Return: 0 on success.
 * Description: the main function of the shell program
 * that read the input from the user and execute it
 * in non-interactive mode or interactive mode.
 * in interactive mode, the shell will print a prompt
 * and wait for the user to enter a command.
 * in non-interactive mode, the shell will read the commands
 * from a file and execute them.
 */
int main(void)
{
	if (isatty(STDIN_FILENO) == 1)
	{
		char *line;
		char **cmds;
		int k = 1;

		signal(SIGINT, _signal_fun);
		while (1)
		{
			write(STDOUT_FILENO, "#cisfun$ ", 10);
			line = read_stdin();
			if (line != NULL)
			{
				cmds = tokenization(line);
				if (_execmd(cmds) > 0)
					_errors(_execmd(cmds), cmds, k);
				free(line);
				free(cmds);
			}
			k++;
		}
		free(line);
		free(cmds);
	}
	else
	{
		char *line, **tokents;

		while (1)
		{
			line = read_line();
			tokents = tokenization(line);
			if (_execmd(tokents) > 0)
				_errors(_execmd(tokents), tokents, 1);
		}
		free(line);
		free(tokents);
	}
	return (0);
}
