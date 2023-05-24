#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char **argv, char **envp)
{

	char *line, *line_copy;
	size_t line_size = 1024;
	char *token, *path_token;
	char **tokens;
	char *env, *en;
	int i = 0;
	struct stat st;
	pid_t child_pid;
	int status;
	en = getenv("PATH");

	while (1)
	{

		printf("#cisfun$ ");
		line = malloc(sizeof(char) * line_size);
		getline(&line, &line_size, stdin);

		line_copy = strdup(line);

		token = strtok(line, " \n");
		if (strcmp(token, "exit") == 0)
		{
			exit(0);
		}
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
		i = 0;

		while (path_token)
		{
			tokens[0] = argv[1];
			child_pid = fork();
			if (child_pid == -1)
			{
				return (1);
			}
			if (child_pid == 0)
			{
				if (execve(tokens[0], tokens, envp) == -1)
				{
					perror("Error:");
					exit(0);
				}
				exit(0);
			}
			else
			{
				wait(&status);
			}
		}
		free(line);
		free(line_copy);
		
	}

	return 0;
}