#include "shell.h"

/**
 * _strncmp - compare two strings.
 * @str1: the first string.
 * @str2: the second string.
 * @n: the number of bytes to compare.
 * Return: 0 if the strings are equal, -1 if not.
 */
int _strncmp(const char *str1, const char *str2, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		if (str1[i] == str2[i])
		{
			continue;
		}
		else
		{
			return (-1);
		}
	}
	return (0);
}
