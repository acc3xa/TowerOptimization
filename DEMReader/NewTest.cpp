#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include "LineAttempt2.h"
#include "NewMap2.h"
#include <vector>


using namespace std;


int main(){
	NewMap2 testmap = NewMap2(42.1, 72.9, 42.1, 70.1, 43.9, 72.9, 43.9, 70.1);
	vector<vector<short int>> path1 = testmap.findPath(70.1, 42.1, 800, 72.9, 43.9, 8);
	cout << "map created" << endl;
	cout << testmap.lineOfSight(path1) << endl;
  	system("pause");

	return 0;
} 
