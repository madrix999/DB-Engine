cc=gcc
CFLAGS=-I. -std=c99

build: main.o dbFunctions.o Functions.o
	$(CC) -o main main.o dbFunctions.o Functions.o -I.

clean:
	rm -rf main main.o dbFunctions.o Functions.o
