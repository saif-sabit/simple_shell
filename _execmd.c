#include "shell.h"
/**
 * execmd- executes the command
 * @argv: array of args
 * @pro: program name
 */

void execmd(char **argv, char *pro)
{
	char *actual_command = NULL;

	actual_command = check_command(argv[0]);
	if (actual_command)
	{
		pid_t child_pid;
		int status;

		child_pid = fork();
		if (child_pid == -1)
		{
			free(actual_command);
			exit(0);
		}
		if (child_pid == 0)
		{
			if (execve(actual_command, argv, NULL) == -1)
			{
				perror(pro);
				free(argv);
				free(actual_command);
				exit(0);
			}
		}
		else
		{
			wait(&status);
			free(actual_command);
			free(argv);
		}
	}
}
