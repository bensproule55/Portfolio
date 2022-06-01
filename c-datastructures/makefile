SRC = ./src/
INC = ./include/
CC = gcc
CFLAGS = -Wall -std=c11 -g

all: main Phonebook.o Trie.o

run: all 
	./main

memory: all 
	valgrind --leak-check=yes main

main: $(SRC)main.c Phonebook.o 
	$(CC) $(CFLAGS) $(SRC)main.c -I$(INC) -o main Phonebook.o 

Phonebook.o: $(SRC)Phonebook.c $(INC)Phonebook.h Trie.o 
	$(CC) $(CFLAGS) $(SRC)Phonebook.c -I$(INC) -c Trie.o

Trie.o: $(SRC)Trie.c $(INC)Trie.h 
	$(CC) $(CFLAGS) $(SRC)Trie.c -I$(INC) -c 

clean:
	rm -r main *.o