/*
 * File: ex_3_gauss_sum.cpp
 * ------------------------
 * This program solves exercise #3.
 * Write a program that implements the gauss sum of the numbers between 1 and 100
 *
 */

#include <iostream>

using namespace std;

int main() {
	int start = 1;
	int end = 100;
	int n = end - start + 1;

	double sum = ( ( n + 1 ) * n ) / 2;
	
	cout << "The sum from 1 to 100 is " << sum << endl;
	return 0;
}


