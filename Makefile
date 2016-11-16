cc=gcc
CFLAGS=-I.

build: main.o dbFunctions.o
	$(CC) -o main main.o dbFunctions.o -I. -std=c99

clean:
	rm -rf main main.o dbFunctions.o