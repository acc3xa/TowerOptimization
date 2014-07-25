#pragma once
#include "Map.h"
#include <iostream>
#include <vector>

using namespace std;

class Tank
{
public:
	Tank();
	Tank(int id, double lat, double lon, double hgt, Map theMap);
	~Tank();

private:
	int tankId;
	vector<vector<short>>* gridPtr;
	double latitude;
	double longitude;
	int xpos;
	int ypos;
	double heigth;
	double elevation;
};

