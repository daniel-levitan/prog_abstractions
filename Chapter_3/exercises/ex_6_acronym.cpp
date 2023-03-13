/**
 * File: ex_6_acronym.cpp
 * -----------------------
 * An acronym is a new word formed by combining, 
 * in order, the initial letters of a series of words.
 * 
 */

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string getAcronym(string str);

int main() {
	string str = "Give me this-acronym";
	cout << "Result: " << getAcronym(str) << endl;
	return 0;
}



string getAcronym(string str) {
	string result = "";

	bool isBeginning = true;

	for (int i = 0; i < str.length(); i++) {
		if (isBeginning){
			result += str[i];
			isBeginning = false;
		}
		else {
			if (!isalpha(str[i]))
				isBeginning = true;
		}
	}

	return result;
}