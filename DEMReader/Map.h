#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <vector>

using namespace std;

class Map
{
public:
	Map();
	~Map();
	void firstInsert(string s);
	void insertGrid(string s);
	vector<vector<short>>* returngrid(int xdiff, int ydiff);
	int getCenterLat();
	int getCenterLong();

private:
	vector<vector<vector<vector<short>>*>> theMap;
	int centerLat;
	int centerLong;

};

