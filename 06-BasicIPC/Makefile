CC = gcc
CFLAGS = -Wall -Wextra -g

# Default target
all: wait-poll-example

wait-poll-example: wait-poll-example.o
	$(CC) $(CFLAGS) -o wait-poll-example wait-poll-example.o

wait-poll-example.o: wait-poll-example.c
	$(CC) $(CFLAGS) -c wait-poll-example.c -o wait-poll-example.o

.PHONY: clean
clean:
	rm -f *.o wait-poll-example