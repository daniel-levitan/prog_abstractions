/**
 * File: ex_7_sum_digits.cpp
 * -------------------------
 * Write a recursive function digitSum(n) that takes a nonnegative integer 
 * and returns the sum of its digits. For example, calling digitSum(1729) 
 * should return 1 + 7 + 2 + 9, which is 19.
 */

#include <iostream>
#include <sstream>
#include <string>
#include "../../libraries/error.h"

using namespace std;

int stringToInteger(string str);
int charToInteger(char c);
string integerToString(int n);
int digitSumIterative(int n);
int digitSum(int n);

int main() {
	cout << "1823 " << digitSum(1823) << endl;
	cout << "1729 " << digitSum(1729) << endl;
	cout << "172  " << digitSum(172) << endl;
	cout << "17   " << digitSum(17) << endl;


	return 0;
}

int digitSum(int n) {
	if (n < 10) 
		return n;
	else {
		return (n % 10) + digitSum(n / 10);
	}
	
}

int digitSumIterative(int n) {
	string str = integerToString(n);
	int sum = 0;
	for (int i = 0; i < str.length(); i++)
		sum += charToInteger(str[i]);
	return sum;
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

int charToInteger(char c) {
    if (c < '0' || c > '9') {
        std::ostringstream out;
        out << "charToInteger: character is not numeric: '" << c
            << "' (ASCII value " << (int) c << ")";
        error(out.str());
    }
    return c - '0';
}

string integerToString(int n) {
	ostringstream stream;
	stream << n;
	return stream.str();
}