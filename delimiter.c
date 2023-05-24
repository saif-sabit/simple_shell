#include "shell.h"

/**
 * delimiter - search for a delimiter.
 * @c: the character to search for.
 * @de: the delimiter string.
 * Return: 1 if found, 0 if not.
 */
unsigned int delimiter(char c, char *de)
{
	while (*de != '\0')
	{
		if (c == *de)
			return (1);
		de++;
	}
	return (0);
}
