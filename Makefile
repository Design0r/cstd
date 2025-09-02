main: test.c
	clang -Wall -Wextra -fsanitize=address -o test test.c && ./test
