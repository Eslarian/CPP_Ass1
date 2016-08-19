#include "maze.h"

using namespace std;

	bool Maze::load_binary(string filename)
	{

		ifstream binfile(filename,ios::binary);
		
		binfile.read((char*) &width, sizeof(int));
		binfile.read((char*) &height, sizeof(int));
		binfile.read((char*) &numEdges, sizeof(int));
			
		
		Edge castEdge;
		for(int i = 0; i < numEdges; ++i)
		{

			// binfile.read((char*) &castEdge.source.x, sizeof(int));
			// binfile.read((char*) &castEdge.source.y, sizeof(int));

			// binfile.read((char*) &castEdge.source.x, sizeof(int));
			// binfile.read((char*) &castEdge.source.y, sizeof(int));
		}

		
		
	
		return false;
	}

