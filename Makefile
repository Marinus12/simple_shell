CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89

SRC = trim.c shell.c command_execute.c display_prompt.c handle_ctrld.c logical_operators.c parse.c execute_command.c inbuilt.c my_getline.c

all: hsh

hsh: $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o hsh

clean:
	rm -f hsh
