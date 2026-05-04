CFLAGS=-Wall -Wextra -g

all: calculate

calculate: server client clean init

server: server.o dijkstra.o
server.o: server.c server.h dijkstra.h

client: client.o dijkstra.o
client.o: client.c client.h dijkstra.h


init:init.o dijkstra.o
init.o:init.c init.h dijkstra.h

clean:clean.o dijkstra.o
clean.o:clean.c clean.h dijkstra.h

dijkstra.o: dijkstra.h dijkstra.c

clean-make: 
	rm -rf *.o rdv_n