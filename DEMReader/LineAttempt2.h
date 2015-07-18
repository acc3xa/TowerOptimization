#pragma once
#include <vector>
#include "Tank.h"
class LineAttempt2
{
public:
	LineAttempt2(int x1, int x2, int y1, int y2);
	~LineAttempt2();
	vector<vector<int>> getPath();
	//vector which contains the path taken
	vector<vector<int>> path;

};

