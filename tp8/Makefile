CFLAGS=-Wall -Wextra -g


all: first second init clean

first: first.o dijkstra.o
first.o: first.h first.c

second: second.o dijkstra.o
second.o: second.h second.c

init:init.o dijkstra.o
init.o:init.c init.h dijkstra.h

clean:clean.o dijkstra.o
clean.o:clean.c clean.h dijkstra.h

dijkstra.o: dijkstra.h dijkstra.c

clean-make: 
	rm -rf *.o first second