#include "Grid.h"

Grid::Grid(){


}

Grid::Grid(string s)
{
	grid.resize(1201);
	for (int i = 0; i < 1201; ++i)
		grid[i].resize(1201);

	ifstream file(s.c_str(), std::ios::in | std::ios::binary);
	if (!file.is_open()){
		cerr << "The file did not open correctly" << endl;
		exit(-1);
	}
	unsigned char buffer[2];
	for (int i = 0; i < 1201; ++i)
	{
		for (int j = 0; j < 1201; ++j)
		{
			if (!file.read(reinterpret_cast<char*>(buffer), sizeof(buffer)))
			{
				std::cout << "Error reading file!" << std::endl;
				exit(-1);
			}
			grid[i][j] = (buffer[0] << 8) | buffer[1];
		}
	}

}


Grid::~Grid()
{
}

short Grid::getElevation(int xpos, int ypos){
	return grid[xpos][ypos];
}