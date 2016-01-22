CP=gcc #Commande du compilateur
CFLAGS=-02 #Option d'optimisation du programme
LDFLAGS= -lmingw32 -lSDLmain -lSDL -mwindows -lSDL2_ttf -lSDL2_mixer -lSDL2_image -Iinclude/ #Linker
EXEC=main #Nom du programme a modifier
FILE=test.c #Nom du code source de test
OBJET=test.o

all: jeux clean

jeux: src/main.c
	gcc src/main.c $(LDFLAGS) -o main

clean:
	rm -rf  *.o
