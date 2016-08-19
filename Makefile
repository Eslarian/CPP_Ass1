CC = g++
CFLAGS = -std=c++14 -Wall -pedantic -g

all: *.cpp *.h
	$(CC) $(CFLAGS) $^ -o  $@ 
