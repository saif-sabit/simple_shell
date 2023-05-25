#include "shell.h"

/**
 * _path_commands - function that finds the path of a command.
 * @cmd: the command to find.
 * Return: the path of the command.
 * Description: function that finds the path of a command using the PATH
 */
char *_path_commands(const char *cmd)
{
	char *excutable = NULL;

	if (cmd[0] == '/')
	{
		if (access(cmd, X_OK) == 0)
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
			if (access(excutable, X_OK) == 0)
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
