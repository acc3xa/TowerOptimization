#include "LineAttempt2.h"
#include <cstdlib>
#include <vector>
#include <cstdlib>
using namespace std;

LineAttempt2::LineAttempt2(int x1, int y1, int x2, int y2)
{
	//create vector to hold the path
	//this can be changed to a different data structure if needed
	path.resize(300);
	for (size_t i = 0; i < 300; i++)
	{
		path[i].resize(2);
	}

	int dx = abs(x2 - x1);
	int dy = abs(y2 - y1);
	//makes it so that it doesnt matter which point appears first
	int sx, sy;
	if (x1 < x2)
		sx = 1;
	else
		sx = -1;
	if (y1 < y2)
		sy = 1;
	else
		sy = -1;

	int error = dx - dy;
	//placeholder
	int e2;
	bool done = 0;
	int pathNum = 0;
	while (done == 0){
		path[pathNum][0] = x1;
		path[pathNum][1] = y1;

		if (x1 == x2 && y1 == y2)
			done = 1;
		
		e2 = 2 * error;
		if (e2 > -dy){
			error = error - dy;
			x1 = x1 + sx;
		}
		if (e2 < dx){
			error = error + dx;
			y1 = y1 + sy;
		}
		pathNum++;

	}
}
vector<vector<int>> LineAttempt2::getPath(){
	return path;
}
LineAttempt2::~LineAttempt2()
{
}
