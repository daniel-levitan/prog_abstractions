#include <iostream>
#include <string>
#include "stringmap.h"
using namespace std;


int main() {
	StringMap myMap;
	cout << "Is empty? " << myMap.isEmpty() << endl;
	myMap.put("a", "a");	
	myMap.put("b", "be");
	myMap.put("d", "de");
	myMap.put("c", "ce");
	myMap.show();
	cout << "Size " << myMap.size() << endl;
	cout << "Is empty? " << myMap.isEmpty() << endl;

	cout << "Contains a? " << myMap.containsKey("a") << endl;
	cout << "Contains e? " << myMap.containsKey("e") << endl;
	// myMap.clear();
	// cout << "Size " << myMap.size() << endl;
	// cout << "Is empty? " << myMap.isEmpty() << endl;	
	return 0;
}