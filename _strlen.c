#include "shell.h"

/**
 * _strlen - get the length of a string.
 * @s: the string.
 * Return: the length of the string.
 * Description: function that get the length of a string.
 */
int _strlen(const char *s)
{
	int length = 0;

	while (s[length] != '\0')
		length++;
	return (length);
}
