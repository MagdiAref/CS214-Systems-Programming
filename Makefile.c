all: factor.c

first: factor.c
	gcc -Wall -Werror -fsanitize=address first.c -o first -lm
clean:
	rm -rf first

