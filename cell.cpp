/******************************************************************************
 * COSC1254 - Programming Using C++
 * Semester 2 2016 - Assignment #1
 * Full Name        : Emile Antognetti
 * Student Number   : s3488934
 * Course Code      : COSC1254_1650
 * Program Code     : BP094
 *****************************************************************************/
using namespace std;

#include "cell.h"
Cell::Cell(int x, int y)
{

	this->x = x;
	this->y = y;

	visited = false;
		
}

Cell::Cell(){}
