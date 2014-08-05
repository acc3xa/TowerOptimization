#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include "Map.h"
#include "Grid.h"
#include "Tank.h"
#include "LineAlgorithm.h"
#include "LineAttempt2.h"
#include "NewMap.h"
#include <vector>


using namespace std;
const int hgt_size = 1201;
vector<vector<int>> pathBetween(Tank tank1, Tank tank2, int* p);
vector <short> elevationProfile(vector<vector<int>> input, int size, Grid* grid1);

int main(){
	bool inputting = 1;
	bool first = 0;
	Map* theMap = new Map();
	NewMap testmap = NewMap(1,2,3,5,6,7,9,20);
	cout << "map created" << endl;
	system("pause");

	/*
	while (inputting == 1){
		string yesno;
		cout << "Enter a .hgt file? Answer 'Y' or 'N':  ";
		cin >> yesno;
		if (yesno == "Y"){
			string input;
			cout << "Enter .HGT Filename: " << endl;
			cin >> input;
			if (first == 0){
				theMap->firstInsert(input);
				first = 1;
			}
			else{
				theMap->insertGrid(input);
			}

		}
		else{
			inputting = 0;
		}

	}

	int id1, id2;
	double lat1, lon1, hgt1, lat2, lon2, hgt2;
	/*cout << "Enter id # of first tank: ";
	cin >> id1;
	cout << "Enter Latitude of first tank: ";
	cin >> lat1;
	cout << "Enter Longitude of first tank: ";
	cin >> lon1;
	cout << "Enter Height of first tank: ";
	cin >> hgt1;
	cout << "Enter id # of second tank: ";
	cin >> id2;
	cout << "Enter Latitude of second tank: ";
	cin >> lat2;
	cout << "Enter Longitude of second tank: ";
	cin >> lon2;
	cout << "Enter Height of second tank: ";
	cin >> hgt2;
	
	id1 = 1;
	id2 = 2;
	lat1 = 43.1;
	lat2 = 43.3;
	lon1 = 71.2;
	lon2 = 71.1;
	hgt1 = 10;
	hgt2 = 5;
	Tank tank1 = Tank(id1, lat1, lon1, hgt1, *theMap);
	Tank tank2 = Tank(id2, lat2, lon2, hgt2, *theMap);

	cout << "TANK 1 INFO" << endl;
	tank1.print();
	cout << "TANK 2 INFO" << endl;
	tank2.print();
/*
	int* p = new int(0);
	vector<vector<int>> testPath = pathBetween(tank1, tank2, p);
	Grid* gptr = theMap->returngrid(0, 0);
	vector<short> test = elevationProfile(testPath, *p, gptr);
	for (int i = 0; i <= *p; i++){
		cout << test.at(i) << endl;
		
	}
	//cout << "done LINE!" << endl;
	LineAttempt2 test = LineAttempt2(tank1.getXpos(), tank1.getYpos(), tank2.getXpos(), tank2.getYpos());
	string testdone;
	vector<vector<int>> testpath = test.getPath();
	for (int j = 0; j < testpath.size(); j++)
	{
		int s1;
		int s2;
		s1 = testpath[j][0];
		s2 = testpath[j][1];
		cout << "Step " << j << " x: " << s1 << " y: " << s2 << endl;
	}
	cout << "LINE FOUND" << endl;
	cin >> testdone;
	if (testdone == "Y")
		exit;
	*/

	
	//return 0;
}

vector<vector<int>> pathBetween(Tank tank1, Tank tank2, int* pathSize){
	vector<vector<int>> path;
	int x, y, xEnd, yEnd;
	int x1 = tank1.getXpos();
	int x2 = tank2.getXpos();
	int y1 = tank1.getYpos();
	int y2 = tank2.getYpos();
	int changeX = x2 - x1;
	int changeY = y2 - y1;
	int twody = 2 * changeY;
	int twodxdy = 2 * (changeY - changeX);
	int dp = twody - changeX;

	//Decide which point comes first to make the slope postive (problem when it come to spanning multiple grids)
	if (x1 > x2) {
		x = x2;
		y = y2;
		xEnd = x1;
		yEnd = y1;
	}
	else {
		x = x1;
		y = y1;
		xEnd = x2;
		yEnd = y2;
	}

	path.resize(1000);
	for (size_t i = 0; i < 1000; i++)
	{
		path[i].resize(2);
	}

	path[0][0] = x;
	path[0][1] = y;
	int pathNum = 1;

	//Bresenham line algorithm
	while ((x < xEnd) &&( y <yEnd)) {
	
		if (dp < 0) {
			x = x + 1;
			dp = dp + twody;
		}
		else {
			y = y + 1;
			dp = dp + twodxdy;
		}
		path[pathNum][0] = x;
		path[pathNum][1] = y;
		pathNum++;
	}
	*pathSize = pathNum;
	return path;
}

vector <short> elevationProfile(vector<vector<int>> input, int psize, Grid* grid1){
	vector <short> profile;
	profile.resize(psize);
	int x = 0;
	int y = 0;
	short elv = 0;
	for (int i = 0; i <= psize; i++){
		x = input[i][0];
		y = input[i][1];
		elv = grid1->getElevation(x, y);
		profile.push_back(elv);
	}
	return profile;
}