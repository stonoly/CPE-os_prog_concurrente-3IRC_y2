CFLAGS=-Wall -Wextra -g


all: guess simple_redirection

guess: guess.o
guess.o: guess.h guess.c

simple_redirection: simple_redirection.o
simple_redirection.o: simple_redirection.h simple_redirection.c

clean: 
	rm -rf *.o guess simple_redirection