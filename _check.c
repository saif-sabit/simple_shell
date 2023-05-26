#include "shell.h"
/**
 * check_command- checks and get command
 * @command: the token that needed to be checked
 * Return: char pointer reoresents comman if exists or null
 */

char *check_command(char *command)
{
	char *path = NULL, *path_copy = NULL, *path_token = NULL, *file_path = NULL;
	struct stat st;

	path = getenv("PATH");
	if (path)
	{
		if (stat(command, &st) == 0)
		{
			free(path);
			return (command);
		}
		path_copy = strdup(path);
		path_token = strtok(path_copy, ":");
		while (path_token != NULL)
		{
			file_path = malloc(strlen(command) + strlen(path_token) + 2);
			strcpy(file_path, path_token);
			strcat(file_path, "/");
			strcat(file_path, command);
			strcat(file_path, "\0");
			if (stat(file_path, &st) == 0)
			{
				free(path);
				free(path_copy);
				free(path_token);
				return (file_path);
			}
			path_token = strtok(NULL, ":");
		}

		free(path);
		free(path_copy);
		free(path_token);
		return (NULL);
	}
	free(path);
	return (NULL);
}
