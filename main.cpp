/******************************************************************************
 * COSC1254 - Programming Using C++
 * Semester 2 2016 - Assignment #1
 * Full Name        : Emile Antognetti
 * Student Number   : s3488934
 * Course Code      : COSC1254_1650
 * Program Code     : BP094
 *****************************************************************************/
using namespace std;

#include "maze.h"
#include "inputhandler.h"

int main(int argc, char * argv[])
{
	
	InputHandler inputHdl;
	Maze localmaze;
	string kek;
	

	if(!inputHdl.check_input(argv,argc))
	{
		cout << "Invalid args, usage:" << endl
		<< "--lb, Load Binary file: filename.maze" << endl
		<< "--sb, Save Binary file: filename.maze" << endl
		<< "--sv, Save SVG file: filename.svg" << endl
		<< "-g, Generate maze: seed width height" << endl;
		return EXIT_FAILURE; 
	}
	
	localmaze.load_binary("../binary.maze");
	Cell test(2,2);
	

	return EXIT_SUCCESS;
}