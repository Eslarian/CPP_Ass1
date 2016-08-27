using namespace std;
#include "utility.h"

class InputHandler
{
	public:
		smatch matchArray;
		vector<string> captures;
		bool check_input(char ** args, int numArgs);
		vector<string> string_splitter(string input, char delim);
		void match_printer();
		

};