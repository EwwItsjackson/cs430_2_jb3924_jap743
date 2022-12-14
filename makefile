CC = gcc
DEBUG = -g
CFLAGS = -Wall -std=c99 -pedantic -c $(DEBUG)
LFLAGS = -Wall -std=c99 -pedantic $(DEBUG)

all : v3test.o v3math.o
	$(CC) $(LFLAGS) v3test.o v3math.o -o v3test -lm

v3test.o : v3test.c v3math.h
	$(CC) $(CFLAGS) v3test.c

v3math.o : v3math.c v3math.h
	$(CC) $(CFLAGS) v3math.c

clean:
	\rm *.o v3test 

