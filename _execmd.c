#include "shell.h"

/**
 * excut_cmd - function that executes a command.
 * @path: the path of the command.
 * @cmd: the command to execute.
 * Return: 0 on success.
 * Description: function that executes a command with the given path.
 */
int excut_cmd(char *path, char **cmd)
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
/**
 * access_path - function that checks if a file exist.
 * @cmd: the command to check.
 * Return: 0 on success.
 * Description: function that checks if a file exist.
 */
int access_path(const char *cmd)
{
	int result = access(cmd, X_OK);

	if (result == -1)
	{
		return (-1);
	}
	else
		return (0);
}
/**
 * find_command_path - function that finds the path of a command.
 * @cmd: the command to find.
 * Return: the path of the command.
 * Description: function that finds the path of a command using the PATH
 */
char *find_command_path(const char *cmd)
{
	char *excutable = NULL;

	if (cmd[0] == '/')
	{
		if (access_path(cmd) == 0)
		{
			excutable = _strdup((char *)cmd);
			return (excutable);
		}
	}
	else
	{
		char *path = _getenv("PATH");
		char *path_copy = _strdup(path);
		char *dir;

		dir = strtok(path_copy, ":");
		while (dir != NULL)
		{
			excutable = malloc(_strlen(dir) + _strlen(cmd) + 2);
			if (excutable == NULL)
			{
				free(excutable);
				return (NULL);
			}
			_strcpy(excutable, dir);
			_strcat(excutable, "/");
			_strcat(excutable, (char *)cmd);
			if (access_path(excutable) == 0)
			{
				free(path_copy);
				return (excutable);
			}
			free(excutable);
			dir = strtok(NULL, ":");
		}
		free(path_copy);
	}

	return (NULL);
}
/**
 * _execmd - function that executes a command.
 * @cmd: the command to execute.
 * Return: 0 on success.
 * Description: function that executes a command with the given path.
 */
int _execmd(char **cmd)
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

	path = find_command_path(cmd[0]);
	if (path != NULL)
	{
		if (excut_cmd(path, cmd) == 0)
		{
			free(path);
			return (0);
		}
		free(path);
		return (1);
	}
	return (1);
}
