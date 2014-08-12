#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <vector>
using namespace std;

class NewMap2
{
public:
	NewMap2(double lat1, double lon1, double lat2, double lon2, double lat3, double lon3, double lat4, double lon4);
	~NewMap2();

private:
	string createFileName(int lat, int lon);
	int findLargest(int p1, int p2, int p3, int p4);
	int findSmallest(int p1, int p2, int p3, int p4);
	void fillMap(int startX, int startY, string fileName);
	string file1;
	string file2;
	string file3;
	string file4;
	int lowY;
	int highY;
	int lowX;
	int highX;
	int rangeY;
	int rangeX;
	vector<vector<short>> theMap;
	
};

