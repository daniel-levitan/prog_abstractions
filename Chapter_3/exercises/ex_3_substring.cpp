/**
 * File: ex_3_substring.cpp
 * ------------------------
 * Implement a function substr(str, pos, n) that returns the substring of str 
 * beginning at position pos and containing at most n characters.
 * 
 * 1. If n is missing or greater than the length of the string, 
 * the substring should extend through the end of the original string.
 * 
 * 2. If pos is greater than the length of the string, 
 * substr should call error with an appropriate message.
 */

#include <iostream>
#include <string>

using namespace std;

string substr(string str, int pos, int n);

int main() {
	string str = "1234567890";


	cout << substr(str, 50, 4) << endl;
	cout << substr(str, 2, 1000) << endl;
	cout << substr(str, 2, 6) << endl;


	return 0;
}

string substr(string str, int pos, int n) {
	if (pos > str.length()) 
		return "Out of bound";

	if (n > str.length())
		n = str.length();

	string newString = "";
	for (int i = pos; i < pos + n; i++) 
		newString += str[i];
	return newString; 
}