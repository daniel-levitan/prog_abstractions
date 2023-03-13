#include <iostream>
#include <string>
#include "vector.h"
using namespace std;

int main() {
	Vector<string> vec;

	cout << "Size " << vec.size() << endl;
	cout << "isEmpty " << vec.isEmpty() << endl;

	// vec.add("ABC");
	// cout << vec.get(0) << endl;

	vec.add("d");
	vec.add("a");
	vec.add("n");
	vec.add("i");
	vec.add("e");
	vec.add("l");

	cout << "Size " << vec.size() << endl;
	cout << "isEmpty " << vec.isEmpty() << endl;


	cout << "vec[0] " << vec.get(0) << endl;
	cout << "vec[0] " << vec[0] << endl;

	vec.add(" ");
	vec.add("L");
	vec.add("E");
	vec.add("V");
	vec.add("I");
	vec.add("T");
	vec.add("A");
	vec.add("N");

	return 0;
}