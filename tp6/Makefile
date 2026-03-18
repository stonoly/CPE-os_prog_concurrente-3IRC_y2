CFLAGS=-Wall -Wextra -g


all: guess simple_redirection pipe_simple

guess: guess.o
guess.o: guess.h guess.c

simple_redirection: simple_redirection.o
simple_redirection.o: simple_redirection.h simple_redirection.c

pipe_simple: pipe_simple.o
pipe_simple.o: pipe_simple.h pipe_simple.c

clean: 
	rm -rf *.o guess simple_redirection pipe_simple