#!/bin/bash

betty-style *.c
betty-doc *.c
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o shell
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o shell_0.3
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o shell_0.4.1
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o simple_shell
sudo chmod +x shell shell_0.3 shell_0.4.1 simple_shell

# valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all ./shell
# gcc -g -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o shell
# export MallocStackLogging=1
# leaks --atExit -- ./shell
# _test/checker.bash ./shell _test/1_task_1/*.bash
# _test/checker.bash ./shell _test/2_task_2/*.bash
# _test/checker.bash ./shell _test/3_task_3/*.bash
# _test/checker.bash ./shell _test/4_task_4/*.bash
