/******************************************************************************
 * COSC1254 - Programming Using C++
 * Semester 2 2016 - Assignment #1
 * Full Name        : Emile Antognetti
 * Student Number   : s3488934
 * Course Code      : COSC1254_1650
 * Program Code     : BP094
 *****************************************************************************/
using namespace std;

#include "cell.h"

typedef std::chrono::high_resolution_clock myclock;

typedef struct Edge
{
	Cell source;
	Cell destination;
}Edge;

class Maze
{
	friend class Cell;

	public:
		//Maze metainfo 
		int width;
		int height;
		int numEdges;
		usigned seed;

		//The positions respectively are left, right, up and down
		int xDirs[NUM_NEIGH] = {-1,1,0,0};
	 	int yDirs[NUM_NEIGH] = {0,0,-1,1};
		
		//Data structures
		Cell entrance;
		Cell exit;
		vector<vector<Cell>> map;
		vector<Edge> edges;
	
		bool load_binary(string filename); 
		bool is_in(Cell checkCell);
		bool is_in(int x, int y);
		bool on_border(Cell checkCell);
		bool add_edge(Edge newEdge);
		bool remove_edge(Edge deadEdge);
		void gen_maze(int width, int height, int seed);

		friend class Cell;



};
