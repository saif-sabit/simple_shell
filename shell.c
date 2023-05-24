#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
/**
 * main - Entry point
 * @argc: number of args
 * @argv: actual args
 * Return: 0 on success 1 on failliar
*/
int main(int argc, char **argv)
{
	char *line, *token;
	size_t buffer = 1;
	int status;
	pid_t child_pid;
	(void) argc;

	while (1)
	{
		printf("#cisfun$");
		line = malloc(sizeof(char) * buffer);
		getline(&line, &buffer, stdin);
		token = strtok(line, "\n");
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}
		if (child_pid == 0)
		{
			if (execve(token, argv, NULL) == -1)
				printf("%s : No such file or directory\n", argv[0]);
		}
		else
			wait(&status);
		free(line);
	}
}
