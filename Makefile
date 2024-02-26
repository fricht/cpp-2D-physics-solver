COMPILER = g++
OUTPUT_DIR = ./build
SRC_DIR = ./src
CPP_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system


$(OUTPUT_DIR)/main: $(OUTPUT_DIR)/main.o $(OUTPUT_DIR)/particle.o $(OUTPUT_DIR)/constraints.o
	$(COMPILER) $(OUTPUT_DIR)/main.o $(OUTPUT_DIR)/particle.o $(OUTPUT_DIR)/constraints.o -o $(OUTPUT_DIR)/main $(CPP_FLAGS)

$(OUTPUT_DIR)/main.o:
	$(COMPILER) -c $(SRC_DIR)/main.cpp -o $(OUTPUT_DIR)/main.o

$(OUTPUT_DIR)/particle.o:
	$(COMPILER) -c $(SRC_DIR)/particle.cpp -o $(OUTPUT_DIR)/particle.o

$(OUTPUT_DIR)/constraints.o:
	$(COMPILER) -c $(SRC_DIR)/constraints.cpp -o $(OUTPUT_DIR)/constraints.o


clean:
	@ echo "cleanning..."
	@ rm -fr $(OUTPUT_DIR)
	@ mkdir $(OUTPUT_DIR)
