#include <maze.h>

using namespace std;

	void load_binary(string filename)
	{

		ifstream binfile(filename,ios::binary);
		
		binfile.read((char*) &width,sizeof(int));
		binfile.read((char*) &height,sizeof(int));
		binfile.read((char*) &numEdges,sizeof(int));
			
		 
		binfile.read((char*) &storage[0],fileSize);
	
	
	}

