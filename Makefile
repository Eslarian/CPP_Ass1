CC = g++
CFLAGS = -std=c++14 -Wall -pedantic

all: main.cpp
	$(CC) $^ -o $@ -g