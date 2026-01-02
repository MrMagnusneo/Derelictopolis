CC = gcc
CFLAGS = -O3 -Wall
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

all: main

main: $(OBJ)
	$(CC) -o $@ $^ -lraylib

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJ) main
