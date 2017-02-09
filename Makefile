CC=gcc

all:
	$(CC) algordenacao3.c -std=c99 -Wall -pedantic -o tes

clean:
	rm tes
