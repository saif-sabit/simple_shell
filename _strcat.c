#include "shell.h"

/**
 * _strcat - concatenate two strings.
 * @dest: the destination string.
 * @src: the source string.
 * Return: the destination string.
 * Description: function that concatenate two strings.
 */
char *_strcat(char *dest, char *src)
{
	int i = 0;
	int r = _strlen(dest);

	while (*(src + i) != '\0')
	{
		*(dest + (r + i)) = *(src + i);
		i++;
	}
	*(dest + (r + i)) = '\0';
	return (dest);
}
