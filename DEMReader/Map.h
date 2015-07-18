#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include "Grid.h"

using namespace std;

class Map
{
public:
	Map();
	~Map();
	void firstInsert(string s);
	void insertGrid(string s);
	Grid* returngrid(int xdiff, int ydiff);
	int getCenterLat();
	int getCenterLong();

private:
	vector<vector<Grid>> theMap;
	int centerLat;
	int centerLong;

};

