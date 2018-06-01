CC=gcc -std=c99
SRC = ./Sources
TESTS = ./Tests
all: build

build: LinkedList

LinkedList:
	$(CC) $(TESTS)/test_LinkedList.c $(SRC)/LinkedList.c $(SRC)/Test.c -o exec_list	-I.

clean:
	rm *.exe