CFLAGS=-Wall -Wextra -g


all: rdv_n init clean

rdv_n: rdv_n.o dijkstra.o
rdv_n.o: rdv_n.c rdv_n.h dijkstra.h

init:init.o dijkstra.o
init.o:init.c init.h dijkstra.h

clean:clean.o dijkstra.o
clean.o:clean.c clean.h dijkstra.h

dijkstra.o: dijkstra.h dijkstra.c

clean-make: 
	rm -rf *.o rdv_n