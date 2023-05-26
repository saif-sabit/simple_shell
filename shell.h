#ifndef SHELL_HEADER
#define SHELL_HEADER
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
void execmd(char **argv, char *pro);
char *check_command(char *command);
#endif 