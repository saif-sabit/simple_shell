#include "shell.h"

/**
 * _strtok - tokenize a string.
 * @str: the string to tokenize.
 * @delim: the delimiter string.
 * Return: a pointer to the next token.
 * Description: function that tokenize a string.
 */
char *_strtok(char *str, char *delim)
{
	static char *old_str;
	char *portion;

	if (str == NULL)
		str = old_str;

	if (str == NULL)
		return (NULL);

	while (1)
	{
		if (_delimiter(*str, delim))
		{
			str++;
			continue;
		}
		if (*str == '\0')
			return (NULL);
		break;
	}
	portion = str;

	while (1)
	{
		if (*str == '\0')
		{
			old_str = str;
			return (portion);
		}
		if (_delimiter(*str, delim))
		{
			*str = '\0';
			old_str = str + 1;
			return (portion);
		}
		str++;
	}
}
