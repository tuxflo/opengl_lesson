CC=g++
CFLAGS=-Wall
LDFLAGS=-lGLU -lglut -lGL

aufg_2.c: 
	$(CC) $(CFLAGS) $@ -o out $(LDFLAGS) 

