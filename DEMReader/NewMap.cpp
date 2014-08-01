#include "NewMap.h"

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

	//find farthest distance of x and y coordinates
	farthestX = farthestPoints(x1, x2, x3, x4);
	farthestY = farthestPoints(y1, y2, y3, y4);
}

//create filename using  a given lat and lon
string NewMap::createFileName(int lat, int lon){
	if (lat > 99){
		return "N" + std::to_string(lat) + "W" + std::to_string(lon) + ".hgt";
	}
	else{
		return "N" + std::to_string(lat) + "W0" + std::to_string(lon) + ".hgt";
	}
}

//given 4 points, finds the two that are farthest apart and gives their difference, used for calculating how big map will be
int NewMap::farthestPoints(int p1, int p2, int p3, int p4){
	int points[4] = { p1, p2, p3, p4 };
	int largestDistance = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = i; j < 4 - i; j++){
			if (abs(points[i] - points[j]) > largestDistance)
				largestDistance = abs(points[i] - points[j]);
		}
	}
	return largestDistance;
}

///NEXT STEP IS TO CREATE THE ACTUAL MAP
//USE A 2DARRRAY OF SIZE LARGESTDISTANCE*1200
//USE CODE FROM OLD GRID CLASS TO IMPORT DATA TO THE 2D ARRAY
//HAVE NOT TESTED ANY CODE IN THIS CLASS YET
NewMap::~NewMap()
{
}
