#include "shell.h"
#include <ctype.h>

/**
 * _exits - exit the shell.
 * @cmd: the command to execute.
 * Return: 0 on success.
 * Description: function that exit the shell
 * with the given status or 0 if no status is given
 */
int _exits(char **cmd)
{
	if (cmd[1] != NULL)
	{
		int n = atoi(cmd[1]);

		if (n == 0 && *cmd[1] != '0')
			return (2);
		free(cmd);
		exit(n);
	}
	free(cmd);
	exit(EXIT_SUCCESS);
}
