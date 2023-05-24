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
	char **tokens;
	char *line, *fullcommand, *real_path, *path, *copy_line, *token, *del = " \n";
	size_t buffer = 1024;
	int status, cmd_found = 1, i = 0;
	pid_t child_pid;
	struct stat st;
	char *token_path;
	(void)argc;

	real_path = getenv("PATH");
	while (1)
	{
		printf("#cisfun$");
		getline(&line, &buffer, stdin);
		copy_line = strdup(line);
		token = strtok(copy_line, del);
		if (strcmp(token, "exit") == 0)
		{
			exit(0);
		}
		for (i = 0; token; i++)
			token = strtok(NULL, del);
		tokens = malloc(sizeof(char *) * i);
		token = strtok(line, del);
		i = 0;
		for (i = 0; token; i++)
		{
			tokens[i] = malloc(strlen(token));
			tokens[i] = token;
			token = strtok(NULL, del);
		}
		/*find_path(tokens[0]);*/

		path = strdup(real_path);
		token_path = strtok(path, ":");
		while (token_path)
		{
			fullcommand = malloc(strlen(tokens[0]) + strlen(token_path) + 2);
			strcpy(fullcommand, token_path);
			strcat(fullcommand, "/");
			strcat(fullcommand, tokens[0]);
			strcat(fullcommand, "\0");
			if (stat(fullcommand, &st) == 0)
			{
				cmd_found = 0;
				child_pid = fork();
				if (child_pid == -1)
				{
					perror("Error:");
					return (1);
				}
				if (child_pid == 0)
				{
					if (execve(fullcommand, tokens, NULL) == -1)
					{
						printf("%s : No such file or directory\n", argv[0]);
					}
				}
				else
					wait(&status);
				break;
			}
			else
			{
				token_path = strtok(NULL, ":");
			}
		}
		if (cmd_found == 1)
		{
			printf("%s: command not found\n", tokens[0]);
		}
		cmd_found = 1;
	}
}
