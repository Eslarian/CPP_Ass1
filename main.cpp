#include "inputhandler.h"

using namespace std;

int main(int argc, char * argv[])
{
	
	InputHandler inputHdl;
	

	if(!inputHdl.check_input(argv,argc))
	{
		cout << "Invalid args, usage:" << endl
		<< "--lb, Load Binary file: filename.maze" << endl
		<< "--sb, Save Binary file: filename.maze" << endl
		<< "--sv, Save SVG file: filename.svg" << endl
		<< "-g, Generate maze: seed width height" << endl;
		return EXIT_FAILURE; 
	}

	

	return EXIT_SUCCESS;
}