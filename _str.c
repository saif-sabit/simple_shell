#include "shell.h"
/**
 * _strchr - a function that locates a character in a string.
 * @s: pointer to string
 * @c: character to be located
 * Return: returns the first occurrence of the character c
 */
char *_strchr(char *s, char c)
{
	while (*s != c)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return (s);
}
/**
 * _strlen - function name
 * Description: calculate the length of a string
 * @s: pointer to string
 * Return: integer length of the string
 */
unsigned int _strlen(char *s)
{
	unsigned int len = 0;

	while (*s)
	{
		len++;
		s++;
	}
	return (len);
}
