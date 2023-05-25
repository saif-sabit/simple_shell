#include "shell.h"
/**
 * tokenization - the tokenization function.
 * @line: the commands line.
 * Return: commands as tokens and NULL if it fails.
 * Description: function that tokenizes the commands line.
 * Reference: https://www.youtube.com/watch?v=Ig4e0PTeJH4
 */
char **tokenization(char *line)
{
	int length = 0;
	int capacity = 16;
	char **tokens;
	char *token;

	tokens = malloc(capacity * sizeof(char *));
	if (tokens == NULL)
	{
		free(tokens);
		return (NULL);
	}

	token = _strtok(line, " \n");
	while (token != NULL)
	{
		tokens[length] = token;
		length++;

		if (length >= capacity)
		{
			capacity += capacity;
			tokens = realloc(tokens, capacity * sizeof(char *));
			if (tokens == NULL)
			{
				free(tokens);
				return (NULL);
			}
		}
		token = _strtok(NULL, " \n");
	}
	tokens[length] = NULL;
	return (tokens);
}
