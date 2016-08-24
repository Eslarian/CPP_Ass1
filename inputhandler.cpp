#include "inputhandler.h"

using namespace std;

			
bool InputHandler::check_input(char ** args, int numArgs)
{
	/*Whilst I've endeavoured to respect the 80 character limit, this particular
	I could not find a way to separate this line of regex out, since it is 
	sensitive to spaces as part of the matching*/
	regex test("^(-g(| [[:digit:]]*)(| [[:digit:]]{1,4})(| [[:digit:]]{1,4})((| --sv [[:alnum:]]*\\.svg)|(| --sb [[:alnum:]]*\\.maze)){1,2}$)|(--lb [[:alnum:]]*\\.maze(| --sv [[:alnum:]]*\\.svg)$)");
	string input;
	for(int i = 1; i < numArgs; i++)
	{
		input.append(args[i]);
		if(i != numArgs-1)
			input.append(" ");
	}

	
	bool retVal = regex_match(input,matchArray,test);
	
	for(unsigned i = 0; i < matchArray.size();i++)
	{
		// cout << "match #" << i << ":" << matchArray[i] << endl;
		captures.push_back(matchArray[i]);
	}

	//cout << captures[0] << endl;

	return retVal;
}

void InputHandler::match_printer()
{

	for(unsigned i = 0; i < matchArray.size();i++)
	{
		cout << "match #" << i << ":" << matchArray[i] << endl;
	}	

}    

vector<string> InputHandler::string_splitter(string input, char delim)
{
	vector<string> splitStrings;
	stringstream stream(input);
	string token;
	while(getline(stream, token, delim))
	{
		splitStrings.push_back(token);
	}

	return splitStrings;

}

