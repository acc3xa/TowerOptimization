#include "NewMap2.h"
#include <vector>


//constructor
NewMap2::NewMap2(double lat1, double lon1, double lat2, double lon2, double lat3, double lon3, double lat4, double lon4)
{
	//cast all the points as ints
	int y1 = (int)lat1;
	int x1 = (int)lon1;
	x1 = x1 + 1;
	int y2 = (int)lat2;
	int x2 = (int)lon2;
	x2 = x2 + 1;
	int y3 = (int)lat3;
	int x3 = (int)lon3;
	x3 = x3 + 1;
	int y4 = (int)lat4;
	int x4 = (int)lon4;
	x4 = x4 + 1;

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
	rangeY = (highY - lowY)+1;
	rangeX = (highX - lowX)+1;

	theMap.resize(rangeY * 1201);
	for (int i = 0; i < rangeY * 1201; i++)
	{
		theMap[i].resize(1201 * rangeX);
	}
	
	//cout << rangeX << endl;
	//cout << rangeY << endl;
	//cout << "map resized" << endl;

	//iterate through map to place data files
	for (int a = highX; a>= lowX; a--){
		for (int b = highY; b >= lowY; b--){
			string currFile = createFileName(a, b);
			cout << currFile << endl;
			fillMap((1200 * (highX - a)), (1200 * (highY - b)), currFile);
		}
	}



	//cout << testmap[0].size() << endl;
	//cout << testmap.size() << endl;
	//cout << findLargest(y1, y2, y3, y4) << endl;
	//cout << findLargest(x1, x2, x3, x4) << endl;
	//cout << createFileName(43, 71) << endl;




}

//create filename using  a given lat and lon
string NewMap2::createFileName(int lat, int lon){
	if (lon > 99){
		return "N" + std::to_string(lon) + "W" + std::to_string(lat) + ".hgt";
	}
	else{
		return "N" + std::to_string(lon) + "W0" + std::to_string(lat) + ".hgt";
	}
}

//given 4 points, find the largets
int NewMap2::findLargest(int p1, int p2, int p3, int p4){
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
int NewMap2::findSmallest(int p1, int p2, int p3, int p4){
	int points[4] = { p1, p2, p3, p4 };
	int smallest = p1;
	for (int i = 1; i < 4; i++)
	{
		if (points[i] < smallest)
			smallest = points[i];
	}
	return smallest;
}



void NewMap2::fillMap(int startX, int startY, string fileName){
	ifstream file(fileName.c_str(), std::ios::in | std::ios::binary);
	if (!file.is_open()){
		cerr << "The file did not open correctly" << endl;
		exit(-1);
	}
	unsigned char buffer[2];
	int upperX = startX + 1200;
	int upperY = startY + 1200;		
	//cout << upperX << " ";
	//cout << upperY << " ";
	for (startY; startY < upperY; startY++)
	{
		//cout << startY << " " << upperY<< " ";
		for (startX; startX < upperX; startX++)
		{
			//cout << startX << " ";
			//cout << startY << " ";
			if (!file.read(reinterpret_cast<char*>(buffer), sizeof(buffer)))
			{
				std::cout << "Error reading file!" << std::endl;
				exit(-1);
			}
			theMap[startY][startX] = (buffer[0] << 8) | buffer[1];
		}
		startX -= 1200;
		
	}

}

vector<vector<short int>> findPath(double lat1, double lon1, double lat2, double lon2){
	int ulX = highX;

	//create vector to hold the path
	//this can be changed to a different data structure if needed
	vector<vector<short int>> path;
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

	return path;
}

//HAVE NOT TESTED ANY CODE IN THIS CLASS YET
NewMap2::~NewMap2()
{
}
