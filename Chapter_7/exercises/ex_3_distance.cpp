/**
 * File: ex_3_distance.cpp
 * -----------------------
 * get Titius Bode Distance 
 * 1   2   3    4
 * 1 - 3 - 6 - 12 - 24
 * d = 
 */

#include <iostream>
#include <string>

using namespace std;

int bodeLaw(int n);
double getTitiusBodeDistance(int n);

int main() {
	// cout << getTitiusBodeDistance(4) << endl;
	
	for (int i = 1; i < 9; i++) 
		cout << getTitiusBodeDistance(i) << endl;
	return 0;
}

double getTitiusBodeDistance(int n) {
	return (4 + bodeLaw(n)) / 10.0;
}

int bodeLaw(int n) {
	if (n == 1)
		return 1;
	if (n == 2)
		return 3;
	else
		return 2 * bodeLaw(n - 1);
}