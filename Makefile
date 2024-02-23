COMPILER = g++
OUTPUT_DIR = ./build
SRC_DIR = ./src


main :
	@ $(COMPILER) $(SRC_DIR)/main.cpp -o $(OUTPUT_DIR)/main

clean :
	@ rm -fr $(OUTPUT_DIR)
	@ mkdir $(OUTPUT_DIR)
