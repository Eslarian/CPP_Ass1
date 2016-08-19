#include <utility.h>

typedef struct Cell
{
	int x;
	int y;
}Cell; 

typedef struct Edge
{
	Cell source;
	Cell destination;
}Edge;

class Maze
{
	int width;
	int height;
	int numEdeges;
	Cell entrance;
	Cell exit;
	
	public: 
	
		void load_binary(string filename); 



};
