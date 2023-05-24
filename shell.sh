#!/bin/bash

betty-style *.c
betty-doc *.c
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o shell
sudo chmod +x shell
