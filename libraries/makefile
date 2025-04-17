# Compiler
CC = gcc

# Include directory (change this to use different header versions)
INCLUDE_DIR = ./v1

# Source and object files
SRC = main.c
OBJ = main.o

# Compiler flags
CFLAGS = -I$(INCLUDE_DIR) -c

# Default target
all: $(OBJ)

# Rule to build object file
$(OBJ): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(OBJ)

# Clean target
clean:
	rm -f $(OBJ)
