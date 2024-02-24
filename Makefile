COMPILER = g++
OUTPUT_DIR = ./build
SRC_DIR = ./src
CPP_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system


$(OUTPUT_DIR)/main: $(OUTPUT_DIR)/main.o
	$(COMPILER) $(OUTPUT_DIR)/main.o -o $(OUTPUT_DIR)/main $(CPP_FLAGS)

$(OUTPUT_DIR)/main.o:
	$(COMPILER) -c $(SRC_DIR)/main.cpp -o $(OUTPUT_DIR)/main.o


clean:
	@ rm -fr $(OUTPUT_DIR)
	@ mkdir $(OUTPUT_DIR)
