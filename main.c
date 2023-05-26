#include "shell.h"
/**
 * main- entry point
 * @ac: number of args
 * @argv: array of actual args
 * Return: 0 on success or 1 on failling
 */
int main(int ac, char **argv)
{
	int nchars_read;
	char *input = NULL;
	size_t buffer = 1;
	char *line;
	char **av;
	(void)ac;

	if (isatty(STDIN_FILENO) == 1)
	{
		while (1)
		{
			write(1, "$ ", 3);
			nchars_read = getline(&input, &buffer, stdin);
			if (nchars_read == -1)
			{
				free(input);
				return (0);
			}
			line = strtok(input, "\n");
			av = malloc(sizeof(char *) * 2);
			av[0] = line;
			av[1] = NULL;
			execmd(av, argv[0]);
		}
	}
	else
	{
		nchars_read = getline(&input, &buffer, stdin);
		if (nchars_read == -1)
		{
			free(input);
			return (0);
		}
		line = strtok(input, "\n");
		av = malloc(sizeof(char *) * 2);
		av[0] = line;
		av[1] = NULL;
		execmd(av, argv[0]);
	}
	return (0);
}
