#include "shell.h"

/**
 * program - the program name.
 * Return: the program name.
 * Description: function that get the program name from /proc.
 * It is used to print the error message. It is used in _errors.c.
 */
char *program(void)
{
	char *progname = NULL;
	char buffer[BUFFER_SIZE], pid[MAX_NUM], procpath[MAX_LENGHT] = "/proc/";
	int fp;

	_itoa(getpid(), pid);
	_strcat(procpath, pid);
	_strcat(procpath, "/cmdline");

	fp = open(procpath, O_RDONLY);
	if (fp != -1)
	{
		int nb = read(fp, buffer, sizeof(progname));

		if (nb != -1)
		{
			progname = malloc(nb * sizeof(char) + 1);
			strncpy(progname, buffer, nb);
			progname[nb] = '\0';
			close(fp);
			return (progname);
		}
		close(fp);
	}
	return (NULL);
}
