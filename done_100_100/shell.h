#ifndef _SHELL_H
#define _SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#define PROMPT "$ "

/**
 * struct built_cmd - Defines the builtins functions.
 * @built_in: The name of the build in command.
 * @fptr: A pointer to the right builtin function.
 */
typedef struct built_cmd
{
	char *built_in;
	void (*fptr)(char *);
} built_t;

extern char **environ;

char *_strcpy(char *dest, char *src);
unsigned int _strlen(char *s);
char *_strdup(char *src);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, int n);
char *_strcat(char *dest, char *src);
void _prompt(char *lineptr, size_t size, int counter, char **argv);
void _exit_shell(char *lineptr);
void _execve(char **linecmd, char *lineptr, int counter, char **argv);
int calculate_tokens(char *lineptr, const char *delim);
char **_parse_to_token(int num_token, char *lineptr, const char *delim);
void _env(char *lineptr);
int _built_in_functions(char **linecmd, char *lineptr);
void _signal_ignore(int sig);
void _free_double_ptr(char **str);
void _exit_simple_shell(char *lineptr);
int _atoi(char *str);
char **_pathtokens(char *str);
char *_exec_path(char **tokens, char *cmd);
char *__path_executable(char *e_path, char *cmd);
char *_getpath(char *cmd);
int _putchar(char c);
void _puts(char *str);
int _print_number(int n);
void _error_execve(char *argv, int counter, char *cmd);
void _print_error(char *argv, int counter, char *cmd);

#endif
