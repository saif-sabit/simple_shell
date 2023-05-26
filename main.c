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
		char *line, **av;
		int nchars_read;
		size_t buffer = 1;
		char *input = NULL;

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
			line = strtok(input, "\n");
			av = malloc(sizeof(char *) * 2);
			av[0] = line;
			av[1] = NULL;
			execmd(av, argv[0]);
		}
	}
	else
	{
		readLine(argv[0]);
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
	char *input = NULL;
	int nchars_read;
	size_t buffer = 1;
	char *line, **av;

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
		execmd(av, pro);
	}
}
