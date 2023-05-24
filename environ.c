#include "shell.h"

/**
 * env - print the environment.
 * @cmd: the command to execute.
 * Return: 0 on success.
 * Description: If no arguments are given, print the entire environment.
 */
int env(char **cmd)
{
	int i;
	char *env_var;
	char *vars[] = {
		"USER",
		"LANGUAGE",
		"SESSION",
		"COMPIZ_CONFIG_PROFILE",
		"SHLVL",
		"HOME",
		"C_IS",
		"DESKTOP_SESSION",
		"LOGNAME",
		"TERM",
		"PATH",
		"DISPLAY",
		NULL,
	};

	for (i = 0; vars[i] != NULL; i++)
	{
		env_var = _getenv(vars[i]);
		if (env_var != NULL)
		{
			write(STDOUT_FILENO, vars[i], _strlen(vars[i]));
			write(STDOUT_FILENO, "=", 1);
			write(STDOUT_FILENO, env_var, _strlen(env_var));
			write(STDOUT_FILENO, "\n", 1);
		}
	}
	*cmd = NULL;
	return (0);
}
