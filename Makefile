CC = g++
CFLAGS = -std=c++14 -Wall -pedantic -g

all: *.cpp
	$(CC) $(CFLAGS) $^ -o  $@ 