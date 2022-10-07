all: sort.c

third: sort.c
	gcc -Wall -Werror -fsanitize=address third.c -o third -lm
clean:
	rm -rf third
