#include <iostream>
#include "stringmap.h"
using namespace std;

int main() {
	StringMap myMap;
	myMap.put("VT", "Vermont");
	myMap.put("RI", "Rhode Island");
	myMap.put("ME", "Maine");
	myMap.put("KS", "Kansas");
	myMap.put("AK", "Alaska");

	// cout << myMap.get("VT") << endl;
	myMap.show();
	
	return 0;
}