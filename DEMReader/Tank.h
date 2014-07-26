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
	int xpos;
	int ypos;
	int getXpos();
	int getYpos();
	void print();
	~Tank();

private:
	int tankId;
	Grid* gridPtr;
	double latitude;
	double longitude;
	
	double heigth;
	short elevation;
};

