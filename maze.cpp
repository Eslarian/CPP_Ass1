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

	void Maze::init_maze(int width, int height, int seed)
	{
		this->width = width;
		this->height = height;

		cout << width << endl;
		cout << height << endl;

		//Reserve space for the map
		map.resize(width,vector<Cell>(height));
		
		//Facsimile cell to initialize cell neighbour vectors
		Cell voidCell(-1,-1);
		//Clock for seeding if seed isn't provided
		myclock::time_point beginning = myclock::now();

		
		//Reserve space for the edges, setting up maze full of walls
		edges.reserve((width+1)*width + (height+1)*height);

		for(int i = 0; i < width; ++i)
		{
			for(int k = 0; k < height; ++k)
			{
				Cell castCell(i,k);
				castCell.neigh.resize(NUM_DIRS,voidCell);
				
				for(int d = 0; d < NUM_DIRS; ++d)
				{
				
					Cell neighCast(i + xDirs[d] , k + yDirs[d]);	 
					if(is_in(neighCast))
						castCell.neigh[d] = neighCast;

					Edge castEdge;

					castEdge.source.x = i + xSourceDirs[d];
					castEdge.source.y = k + ySourceDirs[d];
					castEdge.destination.x = i + xDestDirs[d];
					castEdge.destination.y = k + yDestDirs[d];

					edges.push_back(castEdge);

				
				}
				map[i][k] = castCell;
			}
		}
	
		if(seed == 0)
		{
			
			myclock::duration d = myclock::now() - beginning;
			this->seed = d.count();
		}
		else
		{
			this->seed = seed;
		} 

		mt19937 generator;
		generator.seed((this->seed));
		

		//TODO Need better rng, entrance and exit are always close together
		//Choose random entrance and exit 
		uniform_int_distribution<int> rngWidth(0,width-1);
		uniform_int_distribution<int> rngHeight(0,height-1);
		Cell castEntrance;
		Cell castExit;
		do
		{
			castEntrance.x = rngWidth(generator);
			castEntrance.y = rngHeight(generator);
			
			

		}while(!on_border(castEntrance));

		do
		{

			castExit.x = rngWidth(generator);
			castExit.y = rngHeight(generator);
			
		}while(!on_border(castExit));

		
		this->entrance = castEntrance;
		this->exit = castExit;


	}
	

	void Maze::gen_maze()
	{

		int visitedCells = width * height, ranDir;
		
		mt19937 generator;
		generator.seed((this->seed));

		//Break wall for entrance an exit
		make_gateways(entrance);
		make_gateways(exit);

		
		Cell castCell = map[entrance.x][entrance.y];
		
		Edge castEdge;
		
		uniform_int_distribution<int> rng(0,3);

		while(visitedCells > 0)
		{
			//Set cell to visited, update count;
			if(!map[castCell.x][castCell.y].visited)
			{	
				map[castCell.x][castCell.y].visited = true;
				visitedCells--;
			} 

			ranDir = rng(generator);


			int x = castCell.x + xDirs[ranDir];
			int y = castCell.y + yDirs[ranDir];
			
						
			// if(is_in(x,y))
			// 	castCell = map[x][y];

			//If the calculated neighbour cell is a valid cell
			if(is_in(x, y))
			{
				 
				//If the neighbour hasn't been visited
				if(!map[x][y].visited)
				{

					//Remove the wall between our cell and the neighbour
					castEdge.source.x = castCell.x + xSourceDirs[ranDir];
					castEdge.source.y = castCell.y + ySourceDirs[ranDir];
					castEdge.destination.x = castCell.x + xDestDirs[ranDir];
					castEdge.destination.y = castCell.y + yDestDirs[ranDir];
					remove_edge(castEdge);

										
				}
				//now visit the neighbour
				castCell = map[x][y];

			}


		}



	}

	void Maze::make_gateways(Cell gateway)
	{
		Edge removeEdge;
		if(gateway.x == 0)
		{

			removeEdge.source.x = gateway.x + xSourceDirs[LEFT];
			removeEdge.source.y = gateway.y + ySourceDirs[LEFT];
			removeEdge.destination.x = gateway.x + xDestDirs[LEFT];
			removeEdge.destination.y = gateway.y + yDestDirs[LEFT];
			remove_edge(removeEdge);

		}
		if(gateway.x == width-1)
		{

			removeEdge.source.x = gateway.x + xSourceDirs[RIGHT];
			removeEdge.source.y = gateway.y + ySourceDirs[RIGHT];
			removeEdge.destination.x = gateway.x + xDestDirs[RIGHT];
			removeEdge.destination.y = gateway.y + yDestDirs[RIGHT];
			remove_edge(removeEdge);

		}
		if(gateway.y == 0)
		{

			removeEdge.source.x = gateway.x + xSourceDirs[UP];
			removeEdge.source.y = gateway.y + ySourceDirs[UP];
			removeEdge.destination.x = gateway.x + xDestDirs[UP];
			removeEdge.destination.y = gateway.y + yDestDirs[UP];
			remove_edge(removeEdge);

		}
		if(gateway.y == height-1)
		{

			removeEdge.source.x = gateway.x + xSourceDirs[DOWN];
			removeEdge.source.y = gateway.y + ySourceDirs[DOWN];
			removeEdge.destination.x = gateway.x + xDestDirs[DOWN];
			removeEdge.destination.y = gateway.y + yDestDirs[DOWN];
			remove_edge(removeEdge);

		}

	}

	bool Maze::save_svg(string filename)
	{

		if(!edges.empty()) 
		{
			ofstream svgfile(filename);
			//FIXME assert file is open
			//FIXME So many magic numbers
			
			//Write file headers
			svgfile << "<svg width=\"" << width*100 << "\" ";
			svgfile << "height=\"" << height*100 << "\" ";
			svgfile << "xmlns=\"http://www.w3.org/2000/svg\" >" << endl;

			svgfile << "<rect width=\"" << (width)*200 << "\" ";
			svgfile << "height=\"" << (height)*200 << "\" ";
			svgfile << "style=\"fill:white\" />" << endl;;
			
			//Write in all edges
			for(unsigned int i = 0; i < edges.size(); ++i)
			{
				svgfile << "<line stroke=\"black\" ";

				svgfile << "x1=\"" << edges[i].source.x *100<< "\" ";
				svgfile << "x2=\"" << edges[i].destination.x *100 << "\" ";
				svgfile << "y1=\"" << edges[i].source.y *100<< "\" ";
				svgfile << "y2=\"" << edges[i].destination.y *100<< "\" ";

				svgfile << "stroke-width=\"5\" />" << endl;

			}
			
			//Close svg tag
			svgfile << "</svg>";
					
			return true;

						
		

		} 

		return false;

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

	bool Maze::compare_edge(Edge firstEdge, Edge secondEdge)
	{
		if(firstEdge.source.x == secondEdge.source.x)
		{
			if(firstEdge.source.y == secondEdge.source.y)
			{
				if(firstEdge.destination.x == secondEdge.destination.x)
				{
					if(firstEdge.destination.y == secondEdge.destination.y)
					{

						return true;

					}
				}
			}
		}

		return false;

	}



	void Maze::remove_edge(Edge deadEdge)
	{
		//Also check for the reverse edge
		Edge reverseEdge;
		reverseEdge.source.x = deadEdge.destination.x;
		reverseEdge.source.y = deadEdge.destination.y;
		reverseEdge.destination.x = deadEdge.source.x;
		reverseEdge.destination.y = deadEdge.source.y;


		for(unsigned int i = 0; i < edges.size(); ++i)
		{
			//Remove the edge
			if(compare_edge(edges[i],deadEdge) || \
				compare_edge(edges[i],reverseEdge))
				this->edges.erase(edges.begin() + i);

		}




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
		if(checkCell.x >= 0 && checkCell.x < width && checkCell.y >= 0 && checkCell.y < height)
			return true;

		return false;
	}

	bool Maze::is_in(int x, int y)
	{
		if(x >= 0 && x < width && y >= 0 && y < height)
			return true;

		return false;
	}
