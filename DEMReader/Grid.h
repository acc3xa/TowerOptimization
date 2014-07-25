#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <vector>
using namespace std;

class Grid
{
public:
	Grid();
	Grid(string s);
	~Grid();
	short getElevation(int xpos, int ypos);

private:
	vector<vector<short>> grid;
};

