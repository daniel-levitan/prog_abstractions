/**
 * File: stringmap.cpp
 * -------------------
 * This file implements the stringmap.h interface.
 */

#include <iostream>
#include <string>
#include "stringmap.h"
using namespace std;


/**
 * Implementation notes: StringMap constructor and destructor
 * ----------------------------------------------------------
 * All dynamic allocation ins handled by the Vector class.
 */

StringMap::StringMap() { }
StringMap::~StringMap() { }


/**
 * Implementation notes: put, get
 * ------------------------------
 * These methods use findKey to search for the specified key.
 */

string StringMap::get(const string & key) const {
	int index = findKey(key);
	return (index == -1) ? "" : bindings.get(index).value;
}

void StringMap::put(const string & key, const string & value) {
	int index = findKey(key);
	if (bindings.size() == 0 || index == -1) {
		int i = 0;
		while (i < bindings.size() && key.compare(bindings[i].key) > 0) 
			i++;
		KeyValuePair entry;
		entry.key = key;
		entry.value = value;
		bindings.insert(i, entry);
	} else 
		bindings[index].value = value;
}

void StringMap::show() const {
	for (int i = 0; i < bindings.size(); i++) {
		cout << bindings.get(i).value;
		if (i != bindings.size() - 1)
			cout << " -> ";
	}
	cout << endl;
}


/**
 * Private method: findKey
 * -----------------------
 * Returns the index at which the key appears, or -1 if key is not found.
 */
int StringMap::findKey(const string & key) const {
	// for (int i = 0; i < bindings.size(); i++) {
		// if (bindings.get(i).key == key) return i;
	// }
	// return -1;
	return binarySearch(key, 0, bindings.size() - 1);
}

int StringMap::binarySearch(const std::string & key, int p1, int p2) const {
	if (p1 > p2) return -1;
	int mid = (p1 + p2) / 2;
	if (key == bindings.get(mid).key) return mid;

	if (key.compare(bindings.get(mid).key) < 0) 
		return binarySearch(key, p1, mid - 1);
	else
		return binarySearch(key, mid + 1, p2);
}
