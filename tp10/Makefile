CFLAGS=-Wall -Wextra -g


all: rdv_n init clean prod_conso change

change: init_change clean_change p1 p2 p0

p1: p1.o dijkstra.o
p1.o: p1.c p1.h 

p2: p2.o dijkstra.o
p2.o: p2.c p2.h

p0: p0.o dijkstra.o
p0.o: p0.c p0.h

init_change:init_change.o dijkstra.o
init_change.o:init_change.c init.h dijkstra.h

clean_change:clean_change.o dijkstra.o
clean_change.o:clean_change.c clean.h dijkstra.h

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