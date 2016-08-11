#include "inputhandler.cpp"

using namespace std;

int main(int argc, char * argv[])
{
	
	InputHandler inputManager;

	if(!inputManager.check_input(argv,argc))
	{
		cout << "Invalid args, usage:" << endl
		<< "--lb, Load Binary file: filename.maze" << endl
		<< "--sb, Save Binary file: filename.maze" << endl
		<< "--sv, Save SVG file: filename.svg" << endl
		<< "-g, Generate maze: seed width height" << endl;
		return 0;
	}

	// for(unsigned i = 0; i < m.size();i++)
	// {
	// 		cout << "match #" << i << ":" << m[i] << endl;
	// }	




	

	return 0;
}
