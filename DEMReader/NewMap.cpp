#include "NewMap.h"
#include <vector>

//constructor
NewMap::NewMap(double lat1, double lon1, double lat2, double lon2, double lat3, double lon3, double lat4, double lon4)
{
	//cast all the points as ints
	int y1 = (int)lat1;
	int x1 = (int)lon1;
	int y2 = (int)lat2;
	int x2 = (int)lon2;
	int y3 = (int)lat3;
	int x3 = (int)lon3;
	int y4 = (int)lat4;
	int x4 = (int)lon4;

	//using the coordinates, create the 4 file names
	file1 = createFileName(y1, x1);
	file2 = createFileName(y2, x2);
	file3 = createFileName(y3, x3);
	file4 = createFileName(y4, x4);

	//find highest and lowest x and y coordinates
	lowY = findSmallest(y1, y2, y3, y4);
	highY = findLargest(y1, y2, y3, y4);
	lowX = findSmallest(x1, x2, x3, x4);
	highX = findLargest(x1, x2, x3, x4);
	
	//find the range of x and y to know how big to make the grid
	rangeY = highY - lowY;
	rangeX = highX - lowX;

	vector <vector<int>>testmap = createMap(rangeX, rangeY);
	
	/* used for testing
	cout << testmap[0].size() << endl;
	cout << testmap.size() << endl;
	cout << findLargest(y1, y2, y3, y4) << endl;
	cout << findLargest(x1, x2, x3, x4) << endl;
	cout << createFileName(43, 71) << endl;
	*/


}

//create filename using  a given lat and lon
string NewMap::createFileName(int lat, int lon){
	if (lon > 99){
		return "N" + std::to_string(lat) + "W" + std::to_string(lon) + ".hgt";
	}
	else{
		return "N" + std::to_string(lat) + "W0" + std::to_string(lon) + ".hgt";
	}
}

//given 4 points, find the largets
int NewMap::findLargest(int p1, int p2, int p3, int p4){
	int points[4] = { p1, p2, p3, p4 };
	int largest = p1;
	for (int i = 1; i < 4; i++)
	{
		if (points[i] > largest)
			largest = points[i];
	}
	return largest;
}
//given 4 points, find smallest
int NewMap::findSmallest(int p1, int p2, int p3, int p4){
	int points[4] = { p1, p2, p3, p4 };
	int smallest = p1;
	for (int i = 1; i < 4; i++)
	{
		if (points[i] < smallest)
			smallest = points[i];
	}
	return smallest;
}


//actually create the map
vector<vector<int>> NewMap::createMap(int rgX, int rgY){
	//create map using vector of vectors
	vector<vector<int>> tempMap = {};
	//make the map the right size
	tempMap.resize(rgX * 1200);
	for (int i = 0; i < rgY*1200; i++)
	{
		tempMap[i].resize(1200 * rgY);
	}
	//dont know how to fill in the map with the .hgt files

	
	return tempMap;
}

//HAVE NOT TESTED ANY CODE IN THIS CLASS YET
NewMap::~NewMap()
{
}
