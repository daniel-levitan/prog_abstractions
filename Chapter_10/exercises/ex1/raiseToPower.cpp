/**
 *  File: raiseToPower.cpp
 * 
 * --------------------------
 * Implements the raiseToPower function using divide and conquer.
 * 
 */

#include <iostream>


using namespace std;

int raiseToPower(int base, int exponent) {
	if (exponent == 0) 
		return 1;
	else {
		if ((exponent % 2) == 0)
			return raiseToPower(base, exponent / 2) * raiseToPower(base, exponent / 2);
		else 
			return base * raiseToPower(base, exponent / 2) * raiseToPower(base, exponent / 2);
	}
}


int main() {
	cout << raiseToPower(5, 2) << endl;
	cout << raiseToPower(3, 3) << endl;
	return 0;
}
