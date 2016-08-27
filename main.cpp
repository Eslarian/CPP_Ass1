/******************************************************************************
 * COSC1254 - Programming Using C++
 * Semester 2 2016 - Assignment #1
 * Full Name        : Emile Antognetti
 * Student Number   : s3488934
 * Course Code      : COSC1254_1650
 * Program Code     : BP094
 *****************************************************************************/
using namespace std;

#include "inputhandler.h"

int main(int argc, char * argv[])
{
	
	InputHandler inputHdl;
	
	

	if(!inputHdl.check_input(argv,argc))
	{
		cout << "Invalid args, usage:" << endl
		<< "--lb, Load Binary file: filename.anyextension " << endl
		<< "--sb, Save Binary file: filename.anyextension" << endl
		<< "--sv, Save SVG file: filename.svg" << endl
		<< "--g, Generate maze: seed width height" << endl;
		return EXIT_FAILURE; 
	}
	
	Maze mazeObj;

	inputHdl.execute_commands(mazeObj);
	
	return EXIT_SUCCESS;
}
