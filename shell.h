#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <limits.h>

#define MAX_LENGHT 256
#define MAX_NUM 10
#define BUFFER_SIZE 1024
extern char **environ;

/**
 * struct built - struct for built-in functions.
 * @name: the name of the built-in function.
 * @f: the function to execute.
 * Description: struct for built-in functions.
 */
typedef struct built_in
{
	char *name;
	int (*f)(char **);
} built_in_commands;

void _errors(int status, char **s, int k);
int _strncmp(const char *str1, const char *str2, int n);
char *_getenv(const char *name);
void _itoa(int num, char *str);
int  _excut_cmd(char **cmd);
int _exev_cmd(char *path, char **cmd);
char *_strdup(char *s);
int _strlen(const char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _exits(char **cmd);
char *program(void);
char *read_stdin(void);
char *read_line(void);
char **tokenization(char *line);
int _environment(char **cmd);
char *_strtok(char *str, char *delim);
int space_check(char *line);
unsigned int _delimiter(char c, char *de);
char *_path_commands(const char *cmd);
void _signal_fun(int signal_num);

#endif
