#include "inputhandler.h"

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
	int numEdges;
	Cell entrance;
	Cell exit;
	vector<Edge> edges;
	
	public: 
	
		bool load_binary(string filename); 
		bool is_in(Cell checkCell);




};
