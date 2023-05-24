#!/bin/bash

betty shell.c
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 shell.c -o shell
chmod +x shell
