#include "LineAlgorithm.h"
#include "Tank.h"
using namespace std;

//takes 2 tanks as parameters for now just for testing purposes, these can be changed later

LineAlgorithm::LineAlgorithm(Tank tank1, Tank tank2)
{
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
		
		
	}
	
}
LineAlgorithm::~LineAlgorithm()
{
}
vector<vector<int>> LineAlgorithm::getPath(){
	return path;
}


