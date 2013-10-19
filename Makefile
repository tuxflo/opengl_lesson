CC=g++
CFLAGS=-Wall
LDFLAGS=-lGLU -lglut -lGL

all: 
	$(CC) $(CFLAGS) aufg_2.c -o aufg $(LDFLAGS) 

