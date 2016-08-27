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
	vector<string> splitStrings;
	int w,h,sd;
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
	
	//FIXME SO MANY MAGIC NUMBERS
	Maze mazeObj;

	splitStrings = inputHdl.string_splitter(inputHdl.captures[0],' ');
	if(splitStrings[0] == "-g")
	{
		//FIXME Magic Numbers
		w = 10;
		h = 10;
		sd = 0;
		if(inputHdl.captures[2] != " ")
			sd = stoi(inputHdl.captures[2],nullptr,10);
	
		if(inputHdl.captures[3] != " ")
			w = stoi(inputHdl.captures[3],nullptr,10);

		if(inputHdl.captures[4] != " ")
			h = stoi(inputHdl.captures[4],nullptr,10);

		mazeObj.init_maze(w,h,sd);
		mazeObj.gen_maze();
	
		if(inputHdl.captures[5] != " ")
		{
			splitStrings = inputHdl.string_splitter(inputHdl.captures[5], ' ');
			if(splitStrings[0] == " --sv")
			{
				mazeObj.save_svg(splitStrings[1]);
			}
			else if(splitStrings[0] == " --sv")
			{

				mazeObj.save_binary(splitStrings[1]);

			}
		} 

		if(inputHdl.captures[6] != " ")
		{

			splitStrings = inputHdl.string_splitter(inputHdl.captures[6], ' ');
			if(splitStrings[0] == " --sv")
			{
				mazeObj.save_svg(splitStrings[1]);
			}
			else if(splitStrings[0] == " --sv")
			{

				mazeObj.save_binary(splitStrings[1]);

			}
		} 

	}
	else if(splitStrings[0] == "--lb")
	{
		splitStrings = inputHdl.string_splitter(inputHdl.captures[8],' ');
		mazeObj.load_binary(splitStrings[1]);

		if(inputHdl.captures[9] != " ")
		{
			splitStrings = inputHdl.string_splitter(inputHdl.captures[9],' ');
			if(splitStrings[0] == " --sv")
			{
				mazeObj.save_svg(splitStrings[1]);
			}
		}
	}





	// localmaze.load_binary("../binary.maze");
	// Cell test(2,2);
	// testgen.init_maze(30,30);
	// testgen.gen_maze();
	// testgen.save_svg("mykek.svg");
	// testgen.save_binary("mykek.maze")
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
