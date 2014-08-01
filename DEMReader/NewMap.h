#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include "Grid.h"

class NewMap
{
public:
	NewMap(double lat1, double lon1, double lat2, double lon2, double lat3, double lon3, double lat4, double lon4);
	~NewMap();

private:
	string createFileName(int lat, int lon);
	int farthestPoints(int p1, int p2,int p3, int p4);
	string file1;
	string file2;
	string file3;
	string file4;
	int farthestX;
	int farthestY;

};

