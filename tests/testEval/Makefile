#Makefile
#cible: dependances
#	commandes
#$@ : cible
#$< : nom de la premiere dependance
#$^ : liste des dependances
#$? : liste des dependances plus recentes que la cible
#$* : nom du fichier sans le suffixe

CC=gcc
CFLAGS=-std=c99 -Wextra -Wall -g# -ansi -pedantic
LDFLAGS=-lcmine -lm
EXEC=prog
SRC=../../src
TEST= $(wildcard *.c $(SRC)/*/*.c) 
OBJ= $(TEST:.c=.o)
INCLUDE=

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(INCLUDE) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(INCLUDE) -o $@ -c $< $(CFLAGS)

.PHONY: cleanSimple clean 

cleanSimple:
	rm -rf $(OBJ)

clean: cleanSimple
	rm -rf $(EXEC)	
