.PHONY=all, clean

CPP_FILES=$(wildcard *.cpp)
OBJ_FILES=$(CPP_FILES:%.cpp=%.o)

all: main

main: $(OBJ_FILES)
	g++ -o main $(OBJ_FILES)

%.o: %.cpp %.h debug.h
	g++ -c $<

clean:
	rm -f *.o main
