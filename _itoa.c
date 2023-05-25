#include "shell.h"

/**
 * _itoa - convert an integer to a string.
 * @num: the integer.
 * @str: the string.
 * Return: void.
 * Description: function that convert an integer to a string
 */
void _itoa(int num, char *str)
{
	int i, j;
	char tmp;

	for (i = 0; num != 0; i++)
	{
		str[i] = '0' + (num % 10);
		num /= 10;
	}
	for (j = 0; j < i / 2; j++)
	{
		tmp = str[j];
		str[j] = str[i - j - 1];
		str[i - j - 1] = tmp;
	}
	str[i] = '\0';
}
