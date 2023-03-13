/*
 * File: ex_5_largest.cpp
 * ------------------------
 * This program solves exercise #5.
 * Write a program that reads in a list of integers from the user until 
 * the user enters the value 0 as a sentinel. 
 * 
 * When the sentinel appears, your program should display the largest 
 * value in the list
 *
 */

#include <iostream>
#include "../../libraries/simpio.h"

using namespace std;

int main(){
	int read = -1;
	int largest = -1;

	cout << "Enter integers. Enter 0 to stop." << endl;

	while (read != 0) {
		string prompt = " ? ";
		read = getInteger(prompt);
		if (read > largest) largest = read;
	}

	cout << "The largest number is " << largest << endl;
	return 0;
}