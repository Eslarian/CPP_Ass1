using namespace std;
#include "utility.h"

class InputHandler
{
	private:
		smatch matchArray;
		vector<string> captures;

	public:
		bool check_input(char ** args, int numArgs);
		vector<string> string_splitter(string input, char delim);
		void match_printer();
		

};