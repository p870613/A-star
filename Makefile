.PHONY=all, clean

SRC_DIR=src
BLD_DIR=build
ICD_DIR=include
CPP_FILES=$(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES=$(CPP_FILES:$(SRC_DIR)/%.cpp=$(BLD_DIR)/%.o)

all: main

main: $(OBJ_FILES)
	g++ -o main $(OBJ_FILES)

$(BLD_DIR)/main.o: $(SRC_DIR)/main.cpp
	g++ -I$(ICD_DIR) -c $< -o $@

$(BLD_DIR)/%.o: $(SRC_DIR)/%.cpp $(ICD_DIR)/%.h $(ICD_DIR)/debug.h $(ICD_DIR)/config.h
	@mkdir -p $(BLD_DIR)
	g++ -I$(ICD_DIR) -c $< -o $@

clean:
	rm -rf $(BLD_DIR)
	rm main
