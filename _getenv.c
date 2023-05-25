#include "shell.h"

/**
 * _getenv - get an environment variable.
 * @name: the name of the variable.
 * Return: the value of the variable.
 * Description: function that get an environment variable from environ.
 */
char *_getenv(const char *name)
{
	char **env;
	int len = _strlen(name);

	for (env = environ; *env != NULL; ++env)
	{
		if (_strncmp(*env, name, len) == 0)
			return (&(*env)[len + 1]);
	}
	return (NULL);
}
