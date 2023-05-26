#include "shell.h"
/**
 * main- entry point
 * @ac: number of args
 * @argv: array of actual args
 * Return: 0 on success or 1 on failling
 */
int main(int ac, char **argv)
{
	if (isatty(STDIN_FILENO) == 1)
	{
		char **av;
		int nchars_read, i = 0;
		size_t buffer = 1;
		char *input = NULL, *input_cp, *token;

		(void)ac;
		while (1)
		{
			write(1, "$ ", 3);
			nchars_read = getline(&input, &buffer, stdin);
			if (nchars_read == -1)
			{
				free(input);
				return (0);
			}
			input_cp = strdup(input);
			token = strtok(input_cp, " \n");
			while (token)
			{
				i++;
				token = strtok(NULL, " \n");
			}
			i++;
			av = malloc(sizeof(char *) * i);
			token = strtok(input, " \n");
			i = 0;
			while (token)
			{
				av[i] = malloc(sizeof(char) * strlen(token));
				av[i] = token;
				token = strtok(NULL, " \n");
				i++;
			}
			av[i] = NULL;
			free(token);
			execmd(av, argv[0]);
		}
	}
	return (0);
}
/**
 * readLine - reads the line
 * @pro: progam name
 * Return: string of chars if read or NULL
 */
char *readLine(char *pro)
{
	char *input = NULL, *input_cp;
	int nchars_read;
	size_t buffer = 1;
	char **av;

	while (1)
	{
		write(1, "$ ", 3);
		nchars_read = getline(&input, &buffer, stdin);
		if (nchars_read == -1)
		{
			free(input);
			return (0);
		}
		input_cp = strdup(input);
		printf("%s", input_cp);
		av = malloc(sizeof(char *) * 3);
		av[1] = NULL;
		execmd(av, pro);
	}
}
