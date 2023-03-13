/**
 * File: ex_4_capitalize.cpp
 * -------------------------
 * Implement a function capitalize(str) that returns a string in which 
 * the initial character is capitalized (if it is a letter) and all other 
 * letters are converted to lowercase. Characters other than letters are not 
 * affected. For example, both capitalize("BOOLEAN") and capitalize("boolean") 
 * should return the string "Boolean".
 */

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string capitalize(string str);

int main() {
	cout << capitalize("boolean") << endl;
	cout << capitalize("BOOLEAN") << endl;
	cout << capitalize("Boolean") << endl;
	cout << capitalize("") << endl;

	return 0;
}

string capitalize(string str) {
	if (str.length() < 1)
		return "No string";
	string result = "";

	result += toupper(str[0]);
	for (int i = 1; i < str.length(); i++)
		result += tolower(str[i]);

	return result;
}


