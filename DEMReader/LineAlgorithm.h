#pragma once
#include <vector>
#include "Tank.h"
class LineAlgorithm
{
public:
	LineAlgorithm(Tank tank1, Tank tank2);
	~LineAlgorithm();
	vector<vector<int>> getPath();
	//vector which contains the path taken
	vector<vector<int>> path;

private:
	
	int changeY;
	int	 changeX;
	//these names correspond with the doc from the email
	int	 A;
	int	 B;
	int	 C;
	int P;
	//used to keep track of current location
	int currX;
	int currY;



};

