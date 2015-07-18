#include "LineAlgorithm.h"
#include "Tank.h"
using namespace std;

//takes 2 tanks as parameters for now just for testing purposes, these can be changed later

LineAlgorithm::LineAlgorithm(Tank tank1, Tank tank2)
{
	//Declare and give appropriate value to all required variables
	int x, y, xEnd;
	int x1 = tank1.getXpos();
	int x2 = tank2.getXpos();
	int y1 = tank1.getYpos();
	int y2 = tank2.getYpos();
	changeX = x2 - x1;
	changeY = y2 - y1;
	int twody = 2 * changeY;
	int twodxdy = 2 * (changeY - changeX);
	int dp = twody - changeX;

	//Decide which point comes first to make the slope postive (problem when it come to spanning multiple grids)
	if (x1 > x2) {
		x = x2;
		y = y2;
		xEnd = x1;
	}
	else {
		x = x1;
		y = y1;
		xEnd = x2;
	}


	path.resize(1000);
	for (size_t i = 0; i < 1000; i++)
	{
		path[i].resize(2);
	}

	path[0][0] = x;
	path[0][1] = y;
	pathNum = 1;

	//Bresenham line algorithm
	while (x < xEnd) {
		x = x + 1;
		if (dp < 0) {
			dp = dp + twody;
		}
		else {
			y = y + 1;
			dp = dp + twodxdy;
		}
		path[pathNum][0] = x;
		path[pathNum][1] = y;
		pathNum++;






	/*
	//xpos and ypos should be the relative position on the grid.
	//so it would be the xpos and ypos of the tank
	changeX = tank1.getXpos() - tank2.getXpos();
	changeY = tank1.getYpos() - tank2.getYpos();
	A = 2 * changeY;
	B = A - (2 * changeX);
	P = A - changeX;
	//set current as the beginning of the path, which is 1st position
	currX = tank1.getXpos();
	currY = tank1.getYpos();
	//path starts at 1st position
	//arbitrarily set size as 50
	path.resize(1000);
	for (size_t i = 0; i < 1000; i++)
	{
		path[i].resize(2);
	}
	
	path[0][0] = currX;
	path[0][1] = currY;

	//used to iterate through  the path vector to keep track of all positions
	//start at 1 since beginning position was already added
	int pathNum = 1;
	//simple formula from online, will need to be fixed to handle more complex situations
	//
	//
	//
	//THIS ALGORITHM IS NOT WORKING
	bool done = 0;
	while (done == 0){
		if (P < 0){
			currX--;
			P = A + P;
		}
		if (P >= 0){
			currY--;
			P = B + P;
		}
		cout << pathNum << endl;
		//add the new position to the path vector and increase the pathNum
		path[pathNum][0] = currX;
		path[pathNum][1] = currY;
		pathNum++;
		//stop the algorithm when the path reaches the second point
		if (currX == tank2.getXpos() && currY == tank2.getYpos()){
			done = 1;
		}
		
		*/
	}
	
}
LineAlgorithm::~LineAlgorithm()
{
}
vector<vector<int>> LineAlgorithm::getPath(){
	return path;
}


