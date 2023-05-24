#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/wait.h>

char **get_tokens(char *line, char **tokens);

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: array of arguments
 * @envp: array of environment variables
 *
 * Return: 0 on success
 */

int main(int argc, char **argv, char **envp)
{

	char *line;
	size_t line_size = 1024;
	char **tokens = NULL;
	pid_t child_pid;
	int status;

	(void)argc;
	(void)argv;

	while (1)
	{
		printf("#cisfun$ ");
		line = malloc(sizeof(char) * line_size);
		getline(&line, &line_size, stdin);

		tokens = get_tokens(line, tokens);

		child_pid = fork();
		if (child_pid == -1)
			return (1);
		if (child_pid == 0)
		{
			int result = execve(tokens[0], tokens, envp);

			if (result == -1)
				exit(0);
		}
		else
			wait(&status);

		free(line);
		free(tokens);
	}
	return (0);
}

/**
 * get_tokens - tokenizes a string
 * @line: string to tokenize
 * @tokens: array of tokens
 *
 * Return: array of tokens
 */

char **get_tokens(char *line, char **tokens)
{
	char *token, *line_copy;
	int i = 0;

	line_copy = strdup(line);

	token = strtok(line, " \n");
	if (strcmp(token, "exit") == 0)
		exit(0);

	while (token)
	{
		token = strtok(NULL, " \n");
		i++;
	}

	tokens = malloc(sizeof(char *) * i);
	token = strtok(line_copy, " \n");
	i = 0;
	while (token)
	{
		tokens[i] = malloc(strlen(token) * sizeof(char));
		tokens[i] = token;
		token = strtok(NULL, " \n");
		i++;
	}

	return (tokens);
}
