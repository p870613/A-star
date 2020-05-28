.PHONY=all, clean
dO=main.o block.o field.o game.o

all: main

main: $(dO)
	g++ -o main $(dO)

%.o: %.cpp
	g++ -c $<

clean:
	rm -f *.o main
