/**
 * File: ex_9_eliminateDouble.cpp
 * ------------------------------
 * 
 */

#include <iostream>
#include <string>

using namespace std;

string removeDoubledLetters(string str);
string removeD(string str);

int main() {
	// cout << removeDoubledLetters("bookkepper") << endl;
	// cout << removeDoubledLetters("committee") << endl;
	cout << removeD("bookkepper") << endl;
	cout << removeD("committee") << endl;
	return 0;
}

string removeDoubledLetters(string str) {
	string st = str;
	int i = str.length() - 2;
	
	while (i > 0) {
		if (st[i] == st[i + 1]) 
			st.erase(i + 1, 1);
		i--;
	}
	return st;
}

string removeD(string str) {
	string st = str;
	int i = 0;
	while (i < st.length() - 1) {
		if (st[i] == st[i + 1])
			st.erase(i + 1, 1);
		else
			i++;
	}
	return st;
}