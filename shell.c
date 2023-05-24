#include "shell.h"
/**
 * main- entry point
 * @ac: number of args
 * @argv: array of actual args
 * Return: 0 on success or 1 on failling
*/
int main(int ac, char **argv)
{
	char *input = NULL, *input_cp = NULL;
	size_t buffer = 1;
	int nchars_read;
	int i, num_tokens = 0;
	char *token;

	(void)ac;
	while (1)
	{
		printf("$ ");
		nchars_read = getline(&input, &buffer, stdin);
		if (nchars_read == -1)
			return (-1);
		input_cp = malloc(sizeof(char) * nchars_read);
		if (input_cp == NULL)
			return (-1);
		strcpy(input_cp, input);
		token = strtok(input, " \n");
		while (token != NULL)
		{
			num_tokens++;
			token = strtok(NULL, " \n");
		}
		num_tokens++;

		argv = malloc(sizeof(char *) * num_tokens);
		token = strtok(input_cp, " \n");
		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(token));
			strcpy(argv[i], token);
			token = strtok(NULL, " \n");
		}
		argv[i] = NULL;
		execmd(argv);
	}
	free(input_cp);
	free(input);

	return (0);
}
