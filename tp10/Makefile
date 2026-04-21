CFLAGS=-Wall -Wextra -g


all: rdv_n init clean prod conso init_prod clean_prod

prod_conso: prod conso init_prod clean_prod

prod: prod.o dijkstra.o
prod.o: prod.h prod.c

conso: conso.o dijkstra.o
conso.o: conso.h conso.c

init_prod:init_prod.o dijkstra.o
init_prod.o:init_prod.c init.h dijkstra.h

clean_prod:clean_prod.o dijkstra.o
clean_prod.o:clean_prod.c clean.h dijkstra.h

rdv_n: rdv_n.o dijkstra.o
rdv_n.o: rdv_n.c rdv_n.h dijkstra.h

init:init.o dijkstra.o
init.o:init.c init.h dijkstra.h

clean:clean.o dijkstra.o
clean.o:clean.c clean.h dijkstra.h

dijkstra.o: dijkstra.h dijkstra.c

clean-make: 
	rm -rf *.o rdv_n