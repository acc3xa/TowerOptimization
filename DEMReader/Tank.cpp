#include "Tank.h"


using namespace std;


Tank::Tank(int id, double lat, double lon, double hgt, Map themap){
	tankId = id;
	latitude = lat;
	longitude = lon;
	heigth = hgt;
	int gridlat = (int)lat;
	int gridlong = (int)lon;
	int gridydif = themap.getCenterLat() - gridlat;
	int gridxdif = themap.getCenterLong() - gridlong;
	gridPtr = themap.returngrid(gridxdif, gridydif);
	double latdif = lat - (double)gridlat;
	double longdif = lon - (double)gridlong;
	ypos = (int)((1 - latdif) * 1201);
	xpos = (int)((1 - longdif) * 1201);
	short h = heigth;
	//elevation = h + gridPtr;


}


Tank::~Tank()
{
}
