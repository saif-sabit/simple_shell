#include "shell.h"

/**
 * main - the main function.
 * Return: 0 on success.
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
					error(_execmd(cmds), cmds, k);
				free(line);
				free(cmds);
			}
			k++;
		}
		free(line);
	}
	else
	{
		char *line;
		char **tokents;
		int k = 1;

		while (1)
		{
			line = read_line();
			tokents = tokenization(line);
			if (_execmd(tokents) > 0)
				error(_execmd(tokents), tokents, k);
		}
		free(line);
		free(tokents);
	}
	return (0);
}
