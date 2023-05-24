#!/bin/bash

betty-style *.c
betty-doc *.c
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o shell
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o shell_0.3
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o shell_0.4.1
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o simple_shell
sudo chmod +x shell shell_0.3 shell_0.4.1 simple_shell

# valgrind –leak-check=full –show-leak-kinds=all ./shell 