CC = gcc
CFLAGS = -Wall -Wextra -g

# Default target
all: zombie-example

zombie-example: zombie-example.o process_state.o
	$(CC) $(CFLAGS) -o zombie-example zombie-example.o process_state.o

zombie-example.o: zombie-example.c
	$(CC) $(CFLAGS) -c zombie-example.c -o zombie-example.o

process_state.o: process_state.c
	$(CC) $(CFLAGS) -c process_state.c -o process_state.o

.PHONY: clean
clean:
	rm -f *.o wait-example