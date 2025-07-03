# Compiler and flags
CC = gcc
CFLAGS = -std=c99 -Wall -Wextra `sdl2-config --cflags` -lSDL2_image
LDFLAGS = `sdl2-config --libs` -lSDL2_image

# Directories
SRC_DIR = src
BUILD_DIR = build

# Files
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC))
DEPS = $(wildcard $(SRC_DIR)/*.h)

# Target
TARGET = $(BUILD_DIR)/program.out

# Rules
all: $(TARGET)

$(TARGET): $(OBJ) | $(BUILD_DIR)
	$(CC) $(OBJ) -o $@ $(LDFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(DEPS) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean run
