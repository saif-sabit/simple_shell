#include "shell.h"

/**
 * _excut_cmd - function that executes a command.
 * @cmd: the command to execute.
 * Return: 0 on success.
 * Description: function that executes a command.
 */
int  _excut_cmd(char **cmd)
{
	char *path;
	int i, comp;
	built_in_commands builtin_commands[] = {
		{"exit", _exits},
		{"env", _environment},
		{NULL, NULL},
	};

	for (i = 0; builtin_commands[i].name != NULL; i++)
	{
		comp = _strncmp(cmd[0], builtin_commands[i].name,
						_strlen(builtin_commands[i].name));
		if (comp == 0)
			return (builtin_commands[i].f(cmd));
	}

	path = _path_commands(cmd[0]);
	if (path != NULL)
	{
		if (_exev_cmd(path, cmd) == 0)
		{
			free(path);
			return (0);
		}
		free(path);
		return (1);
	}
	return (1);
}

/**
 * _exev_cmd - function that executes a command.
 * @path: the path to execute.
 * @cmd: the command to execute.
 * Return: 0 on success.
 * Description: function that executes a command with the given path.
 */
int _exev_cmd(char *path, char **cmd)
{
	int status;
	pid_t pid = fork();

	if (pid == 0)
	{
		status = execve(path, cmd, environ);
		if (status == -1)
			return (1);
	}
	else if (pid < 0)
	{
		perror("fork");
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (0);
}
