#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include "Map.h"
#include "Grid.h"
#include "Tank.h"
#include "LineAlgorithm.h"


using namespace std;
const int hgt_size = 1201;

int main(){
	bool inputting = 1;
	bool first = 0;
	Map* theMap = new Map();

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
	*/
	id1 = 1;
	id2 = 2;
	lat1 = 43.07;
	lat2 = 43.1;
	lon1 = 71.1;
	lon2 = 71.2;
	hgt1 = 10;
	hgt2 = 5;
	Tank tank1 = Tank(id1, lat1, lon1, hgt1, *theMap);
	Tank tank2 = Tank(id2, lat2, lon2, hgt2, *theMap);

	cout << "TANK 1 INFO" << endl;
	tank1.print();
	cout << "TANK 2 INFO" << endl;
	tank2.print();

	LineAlgorithm pathTest = LineAlgorithm(tank1, tank2);
	cout << "done LINE!" << endl;


	return 0;
}

