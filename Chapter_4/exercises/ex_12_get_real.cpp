/**
 * File: ex_12_get_real.cpp
 * ------------------------
 * Converting types
 * 
 */

#include <iostream>
#include <sstream>
#include <string>

using namespace std;


float getReal(string prompt);
string getLine(string prompt);

int main() {
	// string line;
	// cout << "Write a full sentence: ";
	// getline(cin, line);
	// line = getLine("Write a full sentence: ");
	// cout << "This is your full sentence: |" << line << "|" << endl;
	float result = getReal("Insert a float: ");
	cout << result << endl;

	return 0;
}

string getLine(string prompt) {
	string line;
	cout << prompt;
	getline(cin, line);
	return line;
}

float getReal(string prompt) {
	float value;
	string line;
	while (true) {
		cout << prompt;
		getline(cin, line);
		istringstream stream(line);
		stream >> value; // >> ws;
		if (!stream.fail() && stream.eof()) break;
		cout << "Illegal integer format. Try again." << endl;
	}
	return value;
  }