/**
 * File: ex_7_square_root.cpp
 * -----------------------
 * This program solves exercise #7 of the new book.
 * 
 * Write a program to find the square root of a number using the 
 * successive approximation method.
 * 
 * 1. Begin by guessing that the square root is x / 2. Call that guess g.
 * 2. The actual square root must lie between g and x / g. At each step in the
 * successive approximation, generate a new guess by averaging g and x / g.
 * 3. Repeat step 2 until the values g and x / g are as close together as the
 * machine precision allows. 
 * 
 * In C++, the best way to check for this condition is to test whether the
 * average is equal to either of the values used to generate it.
 *  
 */

#include <iostream>
#include "../../libraries/simpio.h"
#include "../../libraries/strlib.h"

using namespace std;

double squareRoot(int num);
double absolute(double num);

int main() {
	cout << "Find the square root" << endl;
	int num = getInteger("Insert a number: ");
	cout << "The square root is: " << squareRoot(num) << endl;
	return 0;
}

double absolute(double num) {
	if (num > 0) 
		return num;
	else
		return -num;
}

double squareRoot(int num) {	
	double guess = num / 2;
	while ((absolute(num - guess * guess)) > 0.001) 
		guess = (guess +  num / guess) / 2;
	return guess;
}













