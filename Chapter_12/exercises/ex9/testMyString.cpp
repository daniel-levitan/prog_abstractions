#include <iostream>
#include "mystring.h"

using namespace std;

int main() {
	// string testString = "This is a test string";
	// MyString str = MyString(testString);
	
	MyString str = MyString("This is");
	// cout << endl;
	cout << "Original String: " << str << endl;

	// cout << endl;
	// cout << "Length of the original string: " << testString.length() << endl;
	// cout << "Length of the new string: " << str.length() << endl;
	
	// cout << endl;
	// cout << "Converting from MyString to string..." << endl;
	// cout << "Converted String: " << str << endl;
	// cout << "Converted String: " << str.toString() << endl;

	// cout << endl;
	// cout << "Getting a string element" << endl;
	// cout << "Posistions 0, 1, 2, 3: " << str[0] 
	// 								  << str[1] 
	// 								  << str[2]
	// 								  << str[3]
	// 								  << endl;


	// cout << endl;
	// str += '!';
	// cout << "Testing += " << str << endl;

	// MyString stt = MyString(" nova");
	// stt += '!';
	
	// MyString tt;
	// tt = str + stt;
	// cout << tt << endl;

	// MyString tt = str.substr(2);
	// cout << tt << endl;

	MyString tt = str.substr(1, 2);
	cout << tt << endl;

	return 0;
}