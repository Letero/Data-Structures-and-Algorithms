CC=gcc
all: build

build: LinkedList

LinkedList:
	$(CC) ./Tests/test_LinkedList.c ./Sources/LinkedList.c ./Sources/Test.c -o exec

