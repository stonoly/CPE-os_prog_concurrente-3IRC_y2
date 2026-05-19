CC = gcc

CFLAGS = -Wall -Wextra -g -pthread -Iinclude
LDADD = -pthread

EXEC = bin/marbles

SRC = src/main.c \
      src/billes.c \
      src/travailleur.c \
      src/controleur.c

OBJ = obj/main.o \
      obj/billes.o \
      obj/travailleur.o \
      obj/controleur.o

all: $(EXEC)

$(EXEC): $(OBJ)
	@mkdir -p bin
	$(CC) $^ -o $@ $(LDADD)

obj/%.o: src/%.c include/billes.h
	@mkdir -p obj
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf obj/*.o $(EXEC)