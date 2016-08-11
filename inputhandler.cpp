#include "utility.h"

using namespace std;

class InputHandler
{
	
	private:
		regex validator; 
		smatch match_array;

	public:
		InputHandler():
		validator("^(-g(| [[:digit:]]*)(| [[:digit:]]{1,4})(| [[:digit:]]{1,4})((| --sv [[:alnum:]]*\\.svg)|(| --sb [[:alnum:]]*\\.maze)){1,2}$)|(--lb [[:alnum:]]*\\.maze(| --sv [[:alnum:]]*\\.svg)$)") {}
			
		bool check_input(char ** args, int numArgs)
		{

			string input;
			for(int i = 1; i < numArgs; i++)
			{
				input.append(args[i]);
				if(i != numArgs-1)
					input.append(" ");
			}

			return regex_match(input,match_array,validator);

		}
		
		vector<string> string_splitter(string input, char delim)
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


};


	