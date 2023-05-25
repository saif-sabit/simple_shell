#include "shell.h"
/**
 * main - the main function.
 * Return: 0 on success.
 * Description: the main function of the shell program
 * that read the input from the user and execute it
 * in non-interactive mode or interactive mode.
 * in interactive mode, the shell will print a prompt
 * and wait for the user to enter a command.
 * in non-interactive mode, the shell will read the commands
 * from a file and execute them.
 */
int main(void)
{
	if (isatty(STDIN_FILENO) == 1)
	{
		char *line;
		char **cmds;
		int k = 1;

		signal(SIGINT, _signal_fun);
		while (1)
		{
			write(STDOUT_FILENO, "#cisfun$ ", 10);
			line = read_stdin();
			if (line != NULL)
			{
				cmds = tokenization(line);
				if (_excut_cmd(cmds) > 0)
					_errors(_excut_cmd(cmds), cmds, k);
				free(line);
				free(cmds);
			}
			k++;
		}
		free(line);
		free(cmds);
	}
	else
	{
		char *line, **tokents;

		while (1)
		{
			line = read_line();
			tokents = tokenization(line);
			if (_excut_cmd(tokents) > 0)
				_errors(_excut_cmd(tokents), tokents, 1);
		}
		free(line);
		free(tokents);
	}
	return (0);
}

/**
 * _signal_fun - the signal function.
 * @signal_num: the signal number.
 * Return: void.
 * Description: the program in interactive mode.
 * Reference: https://www.youtube.com/watch?v=Ig4e0PTeJH4
 */

void _signal_fun(int signal_num)
{
	(void)signal_num;
	write(STDOUT_FILENO, "\n", 2);
	write(STDOUT_FILENO, "#cisfun$ ", 10);
}

/**
 * read_stdin - read from stdin.
 * Return: lineptr.
 * Description: function that reads from stdin and returns it.
 * it's used in interactive mode to read the commands.
 * and it's used in non-interactive mode to read the commands from a file.
 */
char *read_stdin(void)
{
	char *lineptr = NULL;
	size_t n = 0;
	int len;

	len = getline(&lineptr, &n, stdin);
	if (len == EOF)
	{
		write(STDOUT_FILENO, "\n", 1);
		free(lineptr);
		exit(EXIT_SUCCESS);
	}
	if (len == -1)
	{
		perror("getline: ");
		exit(EXIT_FAILURE);
	}

	if (space_check(lineptr) == 1)
	{
		free(lineptr);
		return (NULL);
	}

	return (lineptr);
}

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

/*Non Interactive Function*/

/**
 * read_line - read a line from stdin.
 * Return: the line.
 * Description: function that reads a line from stdin and returns it.
 * it's used in non-interactive mode
 */
char *read_line(void)
{
	char *lineptr = NULL;
	size_t n = 0;
	int len;

	len = getline(&lineptr, &n, stdin);
	if (len == EOF)
	{
		free(lineptr);
		exit(EXIT_FAILURE);
	}
	if (len == -1)
	{
		perror("getline: ");
		exit(EXIT_FAILURE);
	}
	return (lineptr);
}
