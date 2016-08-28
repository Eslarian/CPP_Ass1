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

	Maze::Maze(){}

	Maze::Maze(int width, int height, int seed)
	{
		this->width = width;
		this->height = height;
		this->numEdges = (width+1)*width + (height+1)*height;


		//Reserve space for the map
		map.resize(width,vector<Cell>(height));
		
		//Clock for seeding if seed isn't provided
		myclock::time_point beginning = myclock::now();

		
		//Reserve space for the edges, setting up maze full of walls
		edges.reserve(numEdges);


		//Initialize cell map 
		for(int i = 0; i < width; ++i)
		{
			for(int k = 0; k < height; ++k)
			{
				Cell castCell(i,k);
				
				//Build edges (walls) for the cell				
				for(int d = 0; d < NUM_DIRS; ++d)
				{
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
	
		//Default value indicates no seed was given
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

		//Randomly select cells until one is found on the border of the maze
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

		//Store border cells as entrance and exit
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

		//Start with entrance
		//NOTE, should ideally choose arbitrary random cell
		Cell castCell = map[entrance.x][entrance.y];
		
		Edge castEdge;
		
		uniform_int_distribution<int> rng(0,3);

		//Loop until all cells have been visited
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

		//Update number of edges
		numEdges = edges.size();


	}

	//Used to break the walls for the entrance and the exit
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
			assert(svgfile.is_open());
								
			//Write file headers
			svgfile << "<svg width=\"" << width * MAGNIFY << "\" ";
			svgfile << "height=\"" << height * MAGNIFY << "\" ";
			svgfile << "xmlns=\"http://www.w3.org/2000/svg\" >" << endl;

			svgfile << "<rect width=\"" << width * MAGNIFY << "\" ";
			svgfile << "height=\"" << height * MAGNIFY << "\" ";
			svgfile << "style=\"fill:white\"/>" << endl;;
			
			//Write in all edges
			for(unsigned int i = 0; i < edges.size(); ++i)
			{
				svgfile << "<line stroke=\"black\" ";

				svgfile << "x1=\"" << edges[i].source.x *MAGNIFY<< "\" ";
				svgfile << "x2=\"" << edges[i].destination.x *MAGNIFY << "\" ";
				svgfile << "y1=\"" << edges[i].source.y *MAGNIFY<< "\" ";
				svgfile << "y2=\"" << edges[i].destination.y *MAGNIFY<< "\" ";

				svgfile << "stroke-width=\"5\" />" << endl;

			}
			
			//Close svg tag
			svgfile << "</svg>";
					
			return true;

						
		

		} 

		return false;

	}

	bool Maze::save_binary(string filename)
	{
		ofstream binfile(filename,ios::binary);
		assert(binfile.is_open());

		binfile.write((char*) &width, sizeof(int));
		binfile.write((char*) &height, sizeof(int));
		binfile.write((char*) &numEdges, sizeof(int));



		for(unsigned int i = 0; i < edges.size(); ++i)
		{

			binfile.write((char*) &edges[i].source.x, sizeof(int));
			binfile.write((char*) &edges[i].source.y, sizeof(int));

			binfile.write((char*) &edges[i].destination.x, sizeof(int));
			binfile.write((char*) &edges[i].destination.y, sizeof(int));

		}

		return true;


	}


	bool Maze::load_binary(string filename)
	{

		ifstream binfile(filename,ios::binary);
		assert(binfile.is_open());
		
		binfile.read((char*) &width, sizeof(int));
		binfile.read((char*) &height, sizeof(int));
		binfile.read((char*) &numEdges, sizeof(int));
			
		if(width < DEFAULT_W || height < DEFAULT_H || numEdges < 0)
			return false;


		Edge * castEdge = (Edge*)malloc(sizeof(Edge));
		for(int i = 0; i < numEdges; ++i)
		{

			binfile.read((char*) &castEdge->source.x, sizeof(int));
			binfile.read((char*) &castEdge->source.y, sizeof(int));

			binfile.read((char*) &castEdge->destination.x, sizeof(int));
			binfile.read((char*) &castEdge->destination.y, sizeof(int));

			if(!validate_edge(*castEdge))
				return false;
			
			edges.push_back(*castEdge);
			
		}

		return true;
	}


	//Used for deleting edges from the data 
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

	bool Maze::validate_edge(Edge chkEdge)
	{
		if(chkEdge.source.x < 0 || chkEdge.source.x > width)
			return false; 
		
		if(chkEdge.source.y < 0 || chkEdge.source.y > height)
			return false;

		if(chkEdge.destination.x < 0 || chkEdge.destination.x > width)
			return false;

		if(chkEdge.destination.y < 0 || chkEdge.destination.y > height)
			return false;
		

		for(int i = 0; i < NUM_DIRS; ++i)
		{
				if(chkEdge.source.x + xDirs[i] == chkEdge.destination.x)
				{

					if(chkEdge.source.y + yDirs[i] == chkEdge.destination.y)
					{

						return true;	
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
