using namespace std;
#include "maze.h"

#define LOAD_BINARY "--lb"
#define GENERATE "--g"
#define SAVE_BINARY "--sb"
#define SAVE_SVG "--sv"
#define FIRST_COMMAND 0
#define SEED 2
#define WIDTH 3
#define HEIGHT 4
#define SV_OP1 5
#define SV_OP2 6
#define LOAD_COMMAND 8
#define SV_OP3 9
#define DEFAULT_W 10
#define DEFAULT_H 10
#define DEFAULT_SEED 0 


class InputHandler
{
	public:
		smatch matchArray;
		vector<string> captures;
		
		bool check_input(char ** args, int numArgs);
		bool execute_commands(Maze mazeObj);
		vector<string> string_splitter(string input, char delim);

};