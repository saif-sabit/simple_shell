#include "shell.h"

/**
 * _strdup - duplicate a string.
 * @str: the string.
 * Return: the new string.
 * Description: function that duplicate a string.
 */
char *_strdup(char *str)
{
	char *new_string;
	int length;
	int i;

	if (str == NULL)
	{
		return (NULL);
	}
	else
	{
		length = strlen(str);
		new_string = malloc((sizeof(char) * length) + 1);
		if (new_string == NULL)
		{
			free(new_string);
			return (NULL);
		}
		for (i = 0; i < length; i++)
			new_string[i] = str[i];
		new_string[length] = '\0';
	}
	return (new_string);
}
