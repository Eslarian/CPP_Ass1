#include "maze.h"

using namespace std;

int main(int argc, char * argv[])
{
	
	InputHandler inputHdl;
	Maze localmaze;
	

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

	return EXIT_SUCCESS;
}