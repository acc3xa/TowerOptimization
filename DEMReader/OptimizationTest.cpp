#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include "Map.h"


using namespace std;
const int hgt_size = 1201;

vector<short> profile(double x1, double x2, double y1, double y2);

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
	return 0;
}

vector<short> profile(double x1, double x2, double y1, double y2){
	vector<char> profVect;



}