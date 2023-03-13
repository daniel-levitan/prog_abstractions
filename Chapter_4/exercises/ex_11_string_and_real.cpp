/**
 * File: ex_11_string_and_real.cpp
 * -------------------------
 * Converting types
 * 
 */

#include <iostream>
#include <sstream>
#include <string>
#include "../../libraries/error.h"

using namespace std;

int stringToInteger(string str);
double stringToDouble(string str);
string integerToString(int n);
string doubleToString(double n);

int main() {
	cout << stringToInteger("123") << endl;
	cout << stringToDouble("222") << endl;
	cout << stringToDouble("222.33") << endl;
	cout << integerToString(123) << endl;
	cout << doubleToString(123) << endl;
	cout << doubleToString(123.33) << endl;
	return 0;
}

int stringToInteger(string str) {
	istringstream stream(str);
	int value;
	stream >> value; // >> ws;
	if (stream.fail() || !stream.eof()) { 
		error("stringToInteger: Illegal integer format");
	}
	return value;
}

string integerToString(int n) {
	ostringstream stream;
	stream << n;
	return stream.str();
}



double stringToDouble(string str) {
	istringstream stream(str);
	double value;
	stream >> value; // >> ws;
	if (stream.fail() || !stream.eof()) { 
		error("stringToInteger: Illegal integer format");
	}
	return value;
}

string doubleToString(double n) {
	ostringstream stream;
	stream << n;
	return stream.str();
}