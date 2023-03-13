#include <iostream>
#include <string>
#include "stringmap.h"
using namespace std;


int main() {
	StringMap myMap;

	myMap.put("a", "a");	
	myMap.put("b", "be");
	myMap.put("d", "de");
	myMap.put("c", "ce");
	
	myMap.show();

	return 0;
}