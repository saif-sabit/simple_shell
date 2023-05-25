# Simple Shell

## Description
This is a simple shell project for Holberton School. It is a simple UNIX command interpreter that replicates some of the functionalities of the simple shell `sh`. This shell is able to run commands with their full path or without it if they are in the `PATH` environment variable. It also has some built-in commands like `exit`, `env`, `setenv`, `unsetenv` and `cd`.

## Files
- `_test` - Test files for the shell program to run
- `_delimiters` - Delimiters for the tokenizer to use when tokenizing the input
- `_enviroment` - Enviroment variables for the shell program to handle and print
- `_errors` - Error messages for the shell program to handle and print
- `_execmd` - Execute commands with their full path or without it if they are in the `PATH` environment variable
- `_exits` - Exit functions for the shell program to handle
- `_getenv` - Get enviroment variables and return the value of the variable
- `_getline` - Get line from stdin and store it in a buffer string and return the string
- `_itoa` - Convert integer to string and return the string value
- `_signal_functions` - Signal functions for the shell program to handle
- `_space_check` - Check if there is a space in the input
- `_strcat` - Concatenate two strings together and return a new string
- `_strcpy` - Copy a string to another string and return the new string
- `_strdup` - Duplicate a string in a new memory location
- `_strlen` - Get the length of a string in bytes not including the null byte
- `_strcomp` - Compare two strings to see if they are equal
- `_strtok` - Tokenize a string into an array of strings
- `AUTHORS` - Authors file for the project and script
- `generate-authors.sh` - Generate authors file script file
- `main.c` - Main function for the shell program
- `program.h` - Header file for the shell functions and structs
- `read_line.c` - Read line from stdin and store it in a buffer string
- `read_stdin.c` - Read from stdin and tokenize the input
- `tokenization.c` - Tokenize a string into an array of strings
- `shell.h` - Header file for the shell functions
- `shell.sh` - Shell script to test the shell in interactive mode

## Usage
To use the shell program, compile all the `.c` files in the repository and run the executable file:
```
$ gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
$ ./hsh
```

```sh
$ ./shell.sh
```

## Examples
```
$ ./hsh
$ ls -l
total 100
-rw-rw-r-- 1 vagrant vagrant   181 Mar  3 21:01 AUTHORS
-rw-rw-r-- 1 vagrant vagrant  1263 Mar  3 21:01 README.md
-rw-rw-r-- 1 vagrant vagrant   249 Mar  3 21:01 _delimiters
-rw-rw-r-- 1 vagrant vagrant   249 Mar  3 21:01 _enviroment

$ echo "Hello World"
Hello World

$ ls -l /bin
total 1816

```

## Authors
* **Asim Abdelgadir** - [Github](asimsharf) || [Twitter](https://twitter.com/AsimSharf)
* **Saif Sabit** - [Github](saifsabit) || [Twitter](https://twitter.com/saifsabit_)

