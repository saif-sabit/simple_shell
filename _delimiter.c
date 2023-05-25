#include "shell.h"

/**
 * _delimiter - search for a delimiter.
 * @c: the character to search for.
 * @de: the delimiter string.
 * Return: 1 if found, 0 if not.
 * Description: function that search for a delimiter in a string.
 * it's used to tokenize the commands. It's used in tokenization.c.
 */
unsigned int _delimiter(char c, char *de)
{
	while (*de != '\0')
	{
		if (c == *de)
			return (1);
		de++;
	}
	return (0);
}
