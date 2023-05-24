#include "shell.h"
/**
 * execmd- executes the command
 * @argv: array of args
*/

void execmd(char **argv)
{
	char *command = NULL, *actual_command = NULL;

	if (argv)
	{
		command = argv[0];
		actual_command = check_command(command);
		if (actual_command)
		{
			pid_t child_pid;
			int status;

			child_pid = fork();
			if (child_pid == -1)
			{
				perror("Error:");
				exit(1);
			}
			if (child_pid == 0)
			{
				if (execve(actual_command, argv, NULL) == -1)
				{
					perror("Error:");
				}
				sleep(3);
			}
			else
			{
				wait(&status);
			}
		}
		else
		{
			printf("not found\n");
		}
	}
}
