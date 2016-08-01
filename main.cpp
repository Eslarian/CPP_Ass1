#include "utility.h"

using namespace std;

int main(int argc, char * argv[])
{
	string input(*argv);
	regex validator ("^(-g (seed|[[:digit:]]) [[:digit:]]{1,4} [[:digit:]]{1,4}($|( --sv [[:word:]]*\\.svg| --sb [[:word:]]*\\.maze){0,2})|--lb [[:word:]]*\\.maze($| --sv [[:word:]]*\\.svg))$");


	if(argc < 2 || argc > 9)
	{
		cout << "Invalid args, usage:"
		<< "--lb, Load Binary file: filename.maze\n"
		<< "--sb, Save Binary file: filename.maze\n"
		<< "--sv, Save SVG file: filename.svg\n"
		<< "-g, Generate maze: seed width height\n";
		return 0;
	}

	if(regex_match(input,validator))
	{
		cout << "We have takeoff!\n";
	}

	

	return 0;
}
