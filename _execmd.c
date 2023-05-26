#include "shell.h"
/**
 * execmd- executes the command
 * @argv: array of args
 */

void execmd(char **argv, char *pro)
{ /*, *actual_command = NULL;*/
    if (argv)
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
            if (execve(argv[0], argv, NULL) == -1)
            {
                perror(pro);
                free(argv);
                exit(0);
            }
        }
        else
        {
            wait(&status);
            free(argv);
        }
    }
}
