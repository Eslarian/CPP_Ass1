#include "utility.h"

using namespace std;

int main(int argc, char * argv[])
{
	string line;


	if(argc < 2 || argc > 9)
	{
		cout << "Invalid args, usage:"
		<< "--lb, Load Binary file: filename.maze\n"
		<< "--sb, Save Binary file: filename.maze\n"
		<< "--sv, Save SVG file: filename.svg\n"
		<< "-g, Generate maze: seed width height\n";
		return 0;
	}

	if(strcmp(argv[1],LOAD_BINARY) == 0)
	{
			// if()


			cout << "Success!\n";
			return 0;
	}
	else if(strcmp(argv[1],GENERATE) == 0)
	{
			cout << "More Success!\n";
			return 0;
	}

	return 0;
}
