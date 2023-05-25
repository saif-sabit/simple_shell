#include "shell.h"

/**
 * space_check - check if the line is all spaces.
 * @line: the line to check.
 * Return: 1 if all spaces, 0 if not.
 * Description: function that check if the line is all spaces.
 */

int space_check(char *line)
{
	int i;

	for (i = 0; line[i] != '\n'; i++)
	{
		if (line[i] != ' ' && line[i] != '\t')
		{
			return (0);
		}
	}
	return (1);
}
