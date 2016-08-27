###############################################################################
 # COSC1254 - Programming Using C++
 # Semester 2 2016 - Assignment #1
 # Full Name        : Emile Antognetti
 # Student Number   : s3488934
 # Course Code      : COSC1254_1650
 # Program Code     : BP094
###############################################################################
# Setting compiler and flags
CC = g++
CFLAGS = -std=c++14 -Wall -pedantic -g
# Setting object file targets
OBJECTS = main.o maze.o cell.o inputhandler.o
# Setting main compilation
MAIN = ass1

all: $(MAIN)
	@echo Assignment 1 has been compiled. 

$(MAIN): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $(MAIN)

main.o: main.cpp maze.h inputhandler.h
	$(CC) $(CFLAGS) $^ -c  

maze.o: maze.cpp maze.h cell.h
	$(CC) $(CFLAGS) $^ -c

cell.o: cell.cpp cell.h utility.h
	$(CC) $(CFLAGS) $^ -c		

inputhandler.o: inputhandler.cpp inputhandler.h utility.h
	$(CC) $(CFLAGS) $^ -c

###############################################################################
# Clean Directory 

.PHONY: clean

clean:
	rm -rf *.o *.gch *.maze *.svg $(MAIN)

ZIP:
	zip s3488934 *.cpp *.h Makefile *.txt

###############################################################################