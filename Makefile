.PHONY = all, clean

cflag = -Iinclude

all: main

main: main.o
	gcc -o main main.o

%.o: %.c debug.h
	gcc -c $<

clean:
	rm -f *.o main
