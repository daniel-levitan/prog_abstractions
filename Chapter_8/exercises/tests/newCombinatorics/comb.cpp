#include <iostream>
#include <string>
// #include <set>

using namespace std;

void permutations(string str, int index) {
	// string result = "";
	if (str.length() == index)
		cout << str << endl;
	else {

	
}

int main () {
	string str = "abc";
	permutations(str, 1);
	// int index = 0;
	// cout << str.substr(0, index + 1) << endl;
	// cout << str.substr(index + 1) << endl;

	return 0;
}