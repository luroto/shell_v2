CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic
SRC = *.c
NAME = hsh

all:
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)
clean:
	rm $(NAME)
layout:
	./hsh
