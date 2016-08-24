/******************************************************************************
 * COSC1254 - Programming Using C++
 * Semester 2 2016 - Assignment #1
 * Full Name        : Emile Antognetti
 * Student Number   : s3488934
 * Course Code      : COSC1254_1650
 * Program Code     : BP094
 *****************************************************************************/
#include "utility.h"

 class Cell
 {
 	public: 
	 	int x;
	 	int y;
	 	bool visited;
	 	std::vector<Cell> neigh;
	
	 	//Constructors
	 	Cell(int x,int y);
	 	Cell();
	 	
 };