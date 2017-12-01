all: LinkedListExample
CC=g++
CFLAGS=-c -Wall

debug: CXXFLAGS += -DDEBUG -g
debug: CCFLAGS += -DDEBUG -g
debug: LinkedListExample

LinkedListExample: LinkedListExample.cpp
	     g++ -std=c++0x -o LinkedListExample LinkedListExample.cpp 
