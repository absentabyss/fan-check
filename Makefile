CC = gcc
CFLAGS = -c -pedantic-errors -Wall -Wextra -Wsign-conversion -std=c99

CPP = $(wildcard *.c)
OBJ = $(patsubst %.c,%.o,$(wildcard *.c))

FILENAME = fan_check

out: $(OBJ)
	$(CC) -o $(FILENAME) $^

%.o: %.c
	$(CC) -g $(CFLAGS) $^

release:
	$(CC) $(CFLAGS) -O3 $(CPP)
	$(CC) -o $(FILENAME) $(OBJ)

clean:
	rm $(OBJ) $(FILENAME)

