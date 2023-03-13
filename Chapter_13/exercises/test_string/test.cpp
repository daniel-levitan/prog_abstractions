#include <iostream>
#include <string>

using namespace std;

int main() {
	const int CAPACITY = 8;
	char *array;
	int length = 0;
	array = new char[CAPACITY];

	// string src = "This is an example";
	// for (int i = 0; i < src.length(); i++) {
	// 	array[i] = src[i];
	// 	length++;
	// }

	// string complement = " more things that I don't want to appear";
	// int size = complement.length();
	// for (int i = length; i < length + size; i++)
	// 	array[i] = complement[i - length];

	
	// cout << "Array:       " << array << endl;
	// cout << "Arr len:     " << length << endl;
	// cout << "Array:       ";
	// for (int i = 0; i < CAPACITY; i++) cout << array[i];
	// cout << endl;

	// string dest;
	// dest = string(array, length);
	// cout << "First half:  " << dest << endl;

	// string strEnd;
	// strEnd = string(array, length + 1, 0);
	// cout << "Second part: " << strEnd << endl;

	// strEnd = string(array, CAPACITY - 1, 1);
	// cout << "A new attempt: " << strEnd << endl;	
	// cout << string(array, length) + string(array, length, 6) << endl;
	//  		  0123	
	string src = "12345678";
	for (int i = 0; i < CAPACITY; i++)
		array[i] = ' ';
	
	for (int i = 0; i < 4; i++)
		array[i] = src[i];
	
	array[CAPACITY - 1] = '8';

	cout << "Test 1: " << string(array) << endl;
	cout << "Test 2: " << string(array, CAPACITY) << endl;
	cout << "Test 3: " << string(array, 1, 2) << endl;
	cout << "Test 4: " << string(array, CAPACITY - 1, 1) << endl; // This is not a string
	cout << endl;
	cout << "Test 1: " << string(array) << endl;



	return 0;
}