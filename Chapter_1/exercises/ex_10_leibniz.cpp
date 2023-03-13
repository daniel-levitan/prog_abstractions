/*
 * File: ex_10_leibniz.cpp
 * -------------------------
 * This program solves exercise #10.
 *
 * Leibniz series
 * 
 * pi / 4 = aprox 1 - 1/3 + 1/5 - 1/7
 */

#include <iostream>

using namespace std;

int main() {

	int n = 100000;
	
	int mul = 1;
	int count = 1;
	int i = 1;
	double sum = 0;

	while (count < n + 1) {
		// cout << mul * (1 / i) << endl;
		sum += mul * (1.0 / i);
		mul *= -1;	
		i += 2;
		count++;
	}

	cout << "The approximation is " << 4 * sum << endl;
	
	// cout << (-1 * sigNeg) * (1 / nextPrime(i - 1)) << endl;
	
	return 0;
}
