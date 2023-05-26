#include "shell.h"
/**
 * execmd- executes the command
 * @argv: array of args
 * @pro: program name
 */

void execmd(char **av, char *pro)
{
	char *command = NULL, *actual_command = NULL;
	command = av[0];
	actual_command = check_command(command);
	if (actual_command)
	{
		pid_t child_pid;
		int status;
		child_pid = fork();
		if (child_pid == -1)
		{
			exit(0);
		}
		if (child_pid == 0)
		{
			if (execve(actual_command, av, NULL) == -1)
			{
				exit(0);
			}
			sleep(3);
		}
		else{
			wait(&status);
		}

	}
	else
	{
		printf("%s", pro);
	}
}
