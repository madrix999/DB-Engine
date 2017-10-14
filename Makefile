cc=gcc
CFLAGS=-I. -std=c99

build: main.o dbFunctions.o
	$(CC) -o main main.o dbFunctions.o -I.

clean:
	rm -rf main main.o dbFunctions.o
