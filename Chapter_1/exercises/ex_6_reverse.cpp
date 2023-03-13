/*
 * File: ex_6_reverse.cpp
 * ------------------------
 * This program solves exercise #6.
 * write a program that reads in an integer and then displays the number 
 * that has the same digits in the reverse order
 * 
 */

#include <iostream>
#include <string>
#include "../../libraries/simpio.h"

using namespace std;

string reverse(int n);

int main(){
	
	string prompt = "Enter a number: ";
	long n = getLong(prompt);
	cout << "Your reverse is " << reverse(n) << endl;
	return 0;
}

string reverse(int n) {

	string reverse = "";
	string algarism = "";

	while (n > 0) {
		algarism = to_string(n % 10);
		reverse += algarism; 
		n /= 10;
	}
	return reverse;
}

