#include "shell.h"
#include <ctype.h>

/**
 * _exits - exit the shell.
 * @cmd: the command to execute.
 * Return: 0 on success.
 * Description: If no arguments are given, exit with status 0.
 */
int _exits(char **cmd)
{
	if (cmd[1] != NULL)
	{
		if (isdigit(cmd[1][0]))
		{
			exit(atoi(cmd[1]));
		}
		else
		{
			perror("exit");
			return (1);
		}
	}
	*cmd = NULL;
	exit(EXIT_SUCCESS);
}
