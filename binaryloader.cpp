#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

using namespace std;

int main (int argc, char ** argv)
{

	ifstream binfile(argv[1],ios::binary);

	streampos fileSize;

	binfile.seekg(0, std::ios::end);
    fileSize = binfile.tellg();
    binfile.seekg(0, std::ios::beg);


	vector<int> storage;
	storage.reserve(fileSize);
 
	binfile.read((char*) &storage[0],fileSize);

	cout << storage[0] << endl;
	cout << storage[1] << endl;
	cout << storage[2] << endl;
	cout << storage[3] << endl;
	cout << storage[4] << endl;
	cout << storage[5] << endl;
	cout << storage[6] << endl;

	for(unsigned i = 0; i < 6; ++i)
	{
		cout << i << endl;
		cout << storage[i] << endl;
	}

	cout << storage.size()  << endl;

	// std::vector<int> v = std::vector<int>();
 //    v.push_back(17);
 //    v.push_back(12);
 //    v.push_back(23);
 //    v.push_back(42);
 //    for ( auto &i : storage ) {
 //        std::cout << (int)i << std::endl;
 //    }

	return 0;



}