/******************************************************************************
 * COSC1254 - Programming Using C++
 * Semester 2 2016 - Assignment #1
 * Full Name        : Emile Antognetti
 * Student Number   : s3488934
 * Course Code      : COSC1254_1650
 * Program Code     : BP094
 *****************************************************************************/
using namespace std;

#define MAGNIFY 100 
#define DEFAULT_W 10
#define DEFAULT_H 10

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
		unsigned long seed;

		/*The positions respectively are left, right, up and down
		These are used to determined the coordinates of a cell's neighbour*/  	
		int xDirs[NUM_DIRS] = {-1,1,0,0};
	 	int yDirs[NUM_DIRS] = {0,0,-1,1};
		
	 	/*These are used for determining the positions of an edge(wall) 
	 	relative to a cell*/
	 	int xSourceDirs[NUM_DIRS] = {0,1,0,0};
	 	int ySourceDirs[NUM_DIRS] = {0,0,0,1};
	 	int xDestDirs[NUM_DIRS] = {0,1,1,1};
	 	int yDestDirs[NUM_DIRS] = {1,1,0,1};

	 	//Opposite directions
	 	int oppoDirs[NUM_DIRS] = {1,0,3,2};

		//Data structures
		Cell entrance;
		Cell exit;
		vector<vector<Cell>> map;
		vector<Edge> edges;
	
		//Functions
		bool load_binary(string filename);
		bool save_svg(string filename);
		bool save_binary(string filename);
		bool is_in(Cell checkCell);
		bool is_in(int x, int y);
		bool on_border(Cell checkCell);
		bool compare_edge(Edge firstEdge, Edge secondEdge);
		bool validate_edge(Edge chkEdge);
		void make_gateways(Cell gateway);
		void remove_edge(Edge deadEdge);
		void gen_maze();

		Maze(int width, int height, int seed);
		Maze();

		friend class Cell;



};
