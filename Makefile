CC=g++
CFLAGS=-Wall
LDFLAGS=-lGLU -lglut -lGL -lGLEW

all: 
	$(CC) $(CFLAGS) aufg_3.c -o out $(LDFLAGS) 

