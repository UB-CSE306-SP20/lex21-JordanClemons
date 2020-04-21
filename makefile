#Makefile generated automatically by this cool script


#Variables used



CC=gcc
CFLAGS= -g -c -Wall -std=c11 -O0 -fprofile-arcs -ftest-coverage
EXE=main
OBJECTS= blocksWorld.o tests.o




# Recipes


blocksWorld.o: blocksWorld.c blocksWorld.h
	$(CC) $(CFLAGS) -c blocksWorld.c


main.o: main.c blocksWorld.h
	$(CC) $(CFLAGS) -c main.c


tests.o: tests.c
	$(CC) $(CFLAGS) -c tests.c


main: $(OBJECTS)
	 $(CC) -o $(EXE) $(OBJECTS) $(EXE).c

# PHONY targets


.PHONY: clean
clean:
	 rm -rf *~ $(OBJECTS) $(EXE)


#End of make
