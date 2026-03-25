CFLAGS=-Wall -Wextra -g


all: first second

first: first.o djikstra.o
first.o: first.h first.c

second: second.o djikstra.o init.o clean.o
second.o: second.h second.c

init:init.o dijkstra.o
init.o:init.c init.h dijkstra.h

clean:clean.o dijkstra.o
clean.o:clean.c clean.h dijkstra.h

djikstra.o: djikstra.h djikstra.c

clean: 
	rm -rf *.o first second