#include "inputhandler.h"

using namespace std;

			
bool InputHandler::check_input(char ** args, int numArgs)
{
	/*Whilst I've endeavoured to respect the 80 character limit, this particular
	I could not find a way to separate this line of regex out, since it is 
	sensitive to spaces as part of the matching*/
	regex test("^(--g(| [[:digit:]]*)(| [[:digit:]]{1,4})(| [[:digit:]]{1,4})((| --sv [[:alnum:]]*\\.svg)|(| --sb [[:alnum:]]*.[[:alnum:]]*)){1,2}$)|(--lb [[:alnum:]]*.[[:alnum:]]*(| --sv [[:alnum:]]*\\.svg)$)");
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


//Often, input captured by regex contains more than one important datapoint
//As such, match lines are often split into a vector of strings to more easily
//access the relevant information
bool InputHandler::execute_commands(Maze mazeObj)
{
	int w,h,sd;
	vector<string> splitStrings;

	//Since the first capture group contains the entire match, split out the 
	//first command
	splitStrings = string_splitter(captures[FIRST_COMMAND],' ');
	if(splitStrings[0] == GENERATE)
	{
		w = DEFAULT_W;
		h = DEFAULT_H;
		sd = DEFAULT_SEED;

		if(captures[SEED] != "")
			sd = stoi(captures[SEED],nullptr,10);
	
		if(captures[WIDTH] != "")
			w = stoi(captures[WIDTH],nullptr,10);

		if(captures[HEIGHT] != "")
			h = stoi(captures[HEIGHT],nullptr,10);

		mazeObj.init_maze(w,h,sd);
		mazeObj.gen_maze();
	
		if(captures[SV_OP1] != "")
		{
			splitStrings = string_splitter(captures[SV_OP1], ' ');
			if(splitStrings[1] == SAVE_SVG)
			{
				mazeObj.save_svg(splitStrings[2]);
			}
			else if(splitStrings[1] == SAVE_BINARY)
			{

				mazeObj.save_binary(splitStrings[2]);

			}
		} 

		if(captures[SV_OP2] != "")
		{

			splitStrings = string_splitter(captures[SV_OP2], ' ');
			if(splitStrings[1] == SAVE_SVG)
			{
				mazeObj.save_svg(splitStrings[2]);
			}
			else if(splitStrings[1] == SAVE_BINARY)
			{

				mazeObj.save_binary(splitStrings[2]);

			}
		} 

		return true;

	}
	else if(splitStrings[FIRST_COMMAND] == LOAD_BINARY)
	{
		splitStrings = string_splitter(captures[LOAD_COMMAND],' ');
		mazeObj.load_binary(splitStrings[1]);

		if(captures[SV_OP3] != "")
		{
			splitStrings = string_splitter(captures[SV_OP3],' ');
			if(splitStrings[1] == SAVE_SVG)
			{
				mazeObj.save_svg(splitStrings[2]);
			}
		}

		return true;
	}

	return false;

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

