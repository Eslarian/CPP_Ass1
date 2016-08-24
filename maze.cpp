/******************************************************************************
 * COSC1254 - Programming Using C++
 * Semester 2 2016 - Assignment #1
 * Full Name        : Emile Antognetti
 * Student Number   : s3488934
 * Course Code      : COSC1254_1650
 * Program Code     : BP094
 *****************************************************************************/
using namespace std;

#include "maze.h"

	void Maze::gen_maze(int width, int height, int seed = 0)
	{
		this->width = width;
		this->height = height;

		//Reserve space for the map
		map.reserve(width);
		for(auto& i: map)
			i.reserve(height);

		//Initialize maze cell map
		for(int i = 0; i < width; ++i)
		{
			for(int k = 0; k < height; ++k)
			{
				Cell castCell(i,k);
				for(int d = 0; d < NUM_NEIGH; ++d)
				{
					Cell neighCast(i + xDirs[d] , k + yDirs[d]);	 
					if(is_in(neighCast))
						castCell.neigh[d] = neighCast;
				}
				map[i][k] = castCell;
			}
		}

		if(seed = 0)
		{
			myclock::time_point beginning = myclock::now();
			myclock::duration d = myclock::now() - beginning;
			this->seed = d.count();
		}
		else
		{
			this->seed = seed;
		} 

		std::mt19937 generator(this->seed);
		generator.max = 5;
		


	}
	

	bool Maze::load_binary(string filename)
	{

		ifstream binfile(filename,ios::binary);
		
		binfile.read((char*) &width, sizeof(int));
		binfile.read((char*) &height, sizeof(int));
		binfile.read((char*) &numEdges, sizeof(int));
			
		
		Edge castEdge;
		for(int i = 0; i < numEdges; ++i)
		{

			binfile.read((char*) &castEdge.source.x, sizeof(int));
			binfile.read((char*) &castEdge.source.y, sizeof(int));

			binfile.read((char*) &castEdge.destination.x, sizeof(int));
			binfile.read((char*) &castEdge.destination.y, sizeof(int));

			edges.push_back(castEdge);
			
			// TODO: remove debug print
			// cout << "Source: " << edges[i].source.x << "," << edges[i].source.y;
			// cout << " Destination: " << edges[i].destination.x << "," << edges[i].destination.y << endl;
		}

		return false;
	}

	bool Maze::on_border(Cell checkCell)
	{
		if(is_in(checkCell) && (checkCell.x == 0 || checkCell.x == width-1 \
			|| checkCell.y == 0 || checkCell.y == height-1))
			return true;

		return false;
	}

	bool Maze::is_in(Cell checkCell)
	{
		if(checkCell.x <= width && checkCell.y <= height)
			return true;

		return false;
	}

	bool Maze::is_in(int x, int y)
	{
		if(x <= width && y <= height)
			return true;

		return false;
	}
