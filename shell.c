#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

void external(char **argv);

/**
 * main - Entry point
 * @argc: number of args
 * @argv: actual args
 * @argc: number of args
 * Return: 0 on success 1 on failliar
 */

int main(int argc, char **argv)
{
	char *line, *token;
	size_t buffer = 1;
	pid_t child_pid;

	if (argc < 2)
	{

		external(argv);
	}

	while (1)
	{
		printf("#cisfun$ ");
		line = malloc(sizeof(char) * buffer);
		getline(&line, &buffer, stdin);
		token = strtok(line, "\n");
		child_pid = fork();
		if (child_pid == -1)
			exit(1);
		if (child_pid == 0)
		{
			if (execve(token, argv, NULL) == -1)
				printf("%s : No such file or directory\n", argv[0]);
			else
				exit(0);
		}
		else
			wait(NULL);
		free(line);
	}
}

/**
 * external - Entry point
 * @argv: actual args
 * Return: 0 on success 1 on failliar
 */
void external(char **argv)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
		exit(1);
	if (child_pid == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
			printf("%s : No such file or directory\n", argv[0]);
		else
			exit(0);
	}
	else
		wait(NULL);
}
