/*
 * File: ex_9_rounding.cpp
 * -------------------------
 * This program solves exercise #9.
 *
 * 
 * 
 */

#include <iostream>

using namespace std;

int Round(float n);

int main() {

	// float n = 4.9999;
	float n = -4.7;

	cout << "Original " << n << " Round " << Round(n) << endl;
	// cout << "Original " << n << " Int " << -n + int(n) << endl;

	return 0;
}

int Round(float n) {
	if (n >= 0) {
		if ( (n - int(n)) > 0.5 ){
			return int(n + 0.5);
		}
		return int(n);	
	}
	else {
		if ( (-n + int(n)) > 0.5 ){
			return int(n + 0.5);
		}
		return int(n);
	}
}