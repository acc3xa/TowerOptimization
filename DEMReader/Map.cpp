#include "Map.h"


Map::Map()
{
	//Size the map appropriately 
	theMap.resize(15);
	for (int i = 0; i < 15; ++i)
	theMap[i].resize(15);
}


Map::~Map()
{
}



void Map::firstInsert(string s){

	//Buid the grid for first Lat/Long section
	vector<vector<short>>* gridptr;
	vector<vector<short>> grid;
	grid.resize(1201);
	for (int i = 0; i < 1201; ++i)
		grid[i].resize(1201);
	gridptr = &grid;

	//Open and read in file
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

	//Store this first grid in middle of map and lable the center var accordingly 
	theMap[7][7] = gridptr;
	string sy = s.substr(1, 2);
	centerLat = atoi(sy.c_str());
	string sx = s.substr(4, 3);
	centerLong = atoi(sx.c_str());

	cout << "The center of your Map is at: " << endl;
	cout << centerLat << "N" << endl;
	cout << centerLong << "W" << endl;

}

void Map::insertGrid(string s){
	//Buid the grid for Lat/Long section
	vector<vector<short>>* gridptr;
	vector<vector<short>> grid;
	grid.resize(1201);
	for (int i = 0; i < 1201; ++i)
		grid[i].resize(1201);
	gridptr = &grid;

	//Open and read in file
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

	//Read the cordinates in file name and find the position according to relation to center
	string sy = s.substr(1, 2);
	int thisy = atoi(sy.c_str());
	string sx = s.substr(4, 3);
	int thisx = atoi(sx.c_str());
	int ydifference = centerLat - thisy;
	int xdifference = centerLong - thisx;

	cout << "Differnce between Latitudes: " << ydifference << endl;
	cout << "Difference between Long: " << xdifference << endl;

	//Store this first grid in middle of map and lable the center var accordingly 
	theMap[7+xdifference][7-ydifference] = gridptr;

}

int Map::getCenterLat(){
	return centerLat;
}

int Map::getCenterLong(){
	return centerLong;
}

vector<vector<short>>* Map::returngrid(int xdiff, int ydiff){
	return theMap[7 + xdiff][7 - ydiff];
}