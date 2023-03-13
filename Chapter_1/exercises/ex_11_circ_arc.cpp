/*
 * File: ex_11_circ_arc.cpp
 * -------------------------
 * This program solves exercise #11.
 *
 * Circular Arc approximation
 * 
 * 
 */

#include <iostream>
#include <cmath>

using namespace std;

int main() {

	double r = 2; // 2 inches
	int parts = 10000;
	double w = r / parts;
	double x = 0;
	double sum = 0;
	double h = 0;

	for (int i = 0; i < parts; i++) {
		
		x = w * i + w / 2;
		h = sqrt(r * r - x * x);

		// cout << "Position " << x << endl;
		// cout << "Height   " << h << endl;
		sum += h * w;
	}
	cout << "Approximation is " << sum << endl;
	return 0;
}