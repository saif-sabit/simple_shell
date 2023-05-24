#!/bin/bash

betty-style shell.c
betty-doc shell.c
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 shell.c -o shell
sudo chmod +x shell
