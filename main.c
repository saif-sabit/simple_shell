#include "shell.h"
/**
 * main- entry point
 * @ac: number of args
 * @argv: array of actual args
 * Return: 0 on success or 1 on failling
 */
int main(int ac, char **argv)
{
	char *line, **av;
	int nchars_read;
	size_t buffer = 1;
	char *input = NULL;
	char *cmd;

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

	cmd = readLine();
	if (cmd == NULL)
		return (0);
	av = malloc(sizeof(char *) * 2);
	line = strtok(cmd, "\n");
	av[0] = line;
	av[1] = NULL;
	execmd(av, argv[0]);

	return (0);
}
/**
 * readLine - reads the line
 * Return: string of chars if read or NULL
 */
char *readLine()
{
	int nchars_read;
	size_t buffer = 1;
	char *input = NULL;

	nchars_read = getline(&input, &buffer, stdin);
	if (nchars_read == -1)
	{
		free(input);
		return (NULL);
	}
	return (input);
}
