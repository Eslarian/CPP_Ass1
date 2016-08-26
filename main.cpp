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
	Maze testgen;
	string kek;
	Edge test1, test2;
	

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
	testgen.init_maze(5,5);
	testgen.save_svg("mykek.svg");
	//TODO Remove debugs
	// test1.source.x = 1;
	// test1.source.y = 1;
	// test1.destination.x = 2;
	// test1.destination.y = 2;

	// test2.source.x = 1;
	// test2.source.y = 1;
	// test2.destination.x = 3;
	// test2.destination.y = 2;

	// if(testgen.compare_edge(test1,test2))
	// 	cout << "Yippy kiyay" << endl;
	

	return EXIT_SUCCESS;
}
