CP=gcc #Commande du compilateur
CFLAGS=-02 #Option d'optimisation du programme
LDFLAGS=-lSDL -lSDL_ttf -lSDL_mixer -Iinclude/ #Linker
EXEC=main #Nom du programme a modifier
FILE=test.c #Nom du code source de test
OBJET=test.o

all: jeux clean 

jeux: src/main.c
	gcc src/main.c $(LDFLAGS) -o main

clean:
	rm -rf  *.o
