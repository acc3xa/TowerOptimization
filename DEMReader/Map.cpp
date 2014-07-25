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

	//Store this first grid in middle of map and lable the center var accordingly 
	theMap[7][7] = Grid(s);
	string sy = s.substr(1, 2);
	centerLat = atoi(sy.c_str());
	string sx = s.substr(4, 3);
	centerLong = atoi(sx.c_str());

	cout << "The center of your Map is at: " << endl;
	cout << centerLat << "N" << endl;
	cout << centerLong << "W" << endl;

}

void Map::insertGrid(string s){

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
	theMap[7 + xdifference][7 - ydifference] = Grid(s);

}

int Map::getCenterLat(){
	return centerLat;
}

int Map::getCenterLong(){
	return centerLong;
}


Grid* Map::returngrid(int xdiff, int ydiff){
	Grid* gridptr = &theMap[7 + xdiff][7 - ydiff];
	return gridptr;
	}