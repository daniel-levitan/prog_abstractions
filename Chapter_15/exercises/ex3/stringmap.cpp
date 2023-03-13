#include <iostream>
#include <string>
#include "stringmap.h"
#include "../../../libraries/error.h"
using namespace std;

StringMap::StringMap() {
	capacity = INITIAL_CAPACITY;
	count = 0;
	bindings = new KeyValuePair[capacity];
}

StringMap::~StringMap() {
	delete[] bindings;
}

string StringMap::get(const string & key) const {
	int index = findKey(key);
	return (index == -1) ? "" : bindings[index].value;
}

void StringMap::add(const string & key, const string & value) {
	insert(count, key, value);
}
 
void StringMap::insert(int index, const string & key, const string & value) {
	if (count == capacity) expandCapacity();
	if (index < 0 || index > count) error("insert: index out of bounds.");
	for (int i = count; i > index; i--)
		bindings[i] = bindings[i - 1];

	KeyValuePair entry;
	entry.key = key;
	entry.value = value;
	bindings[index] = entry;
	count++;
}	

void StringMap::put(const string & key, const string & value) {
	int index = findKey(key);
	if (count == 0 || index == -1) {
		int i = 0;
		while (i < count && key.compare(bindings[i].key) > 0)
			i++;
		KeyValuePair entry;
		entry.key = key;
		entry.value = value;
		insert(i, key, value);
	} else
		bindings[index].value = value;



	// ISTO ESTA FUNCIONANDO
	// if (count == capacity) expandCapacity();
	// int index = findKey(key);
	// if (index == -1) {
	// 	KeyValuePair entry;
	// 	entry.key = key;
	// 	index = count;
	// 	// bindings[count].value = value; 	// review this line
	// }
	// bindings[index].value = value;
	// count++;
}

int StringMap::size() const {
	return count;
}

bool StringMap::isEmpty() const {
	return count == 0;
}

bool StringMap::containsKey(const std::string & key) const {
	if (findKey(key) != -1)
		return true;
	return false;
}

void StringMap::clear() {
	count = 0;
}

void StringMap::show() const {
	for (int i = 0; i < count + 1; i++) {
		cout << bindings[i].value;
		if (i < count - 1)
			cout << " -> ";
	}
	cout << endl;
}

int StringMap::findKey(const string & key) const {
	// for (int i = 0; i < count; i++) {
	// 	if (bindings[i].key == key) return i;
	// }
	// return -1;
	return binarySearch(key, 0, count - 1);
}

int StringMap::binarySearch(const std::string & key, int p1, int p2) const {
	if (p1 > p2) return -1;
	int mid = (p1 + p2) / 2;
	if (key == bindings[mid].key) return mid;

	if (key.compare(bindings[mid].key) < 0) 
		return binarySearch(key, p1, mid - 1);
	else
		return binarySearch(key, mid + 1, p2);
}

StringMap::StringMap(const StringMap & src) {
	deepCopy(src);
}

StringMap & StringMap::operator=(const StringMap & src) {
	if (this != &src) {
		delete[] bindings;
		deepCopy(src);
	}
	return *this;
}

void StringMap::deepCopy(const StringMap & src) {
	capacity = src.count + INITIAL_CAPACITY;
	this->bindings = new KeyValuePair[capacity];
	for (int i = 0; i < src.count; i++)
		bindings[i] = src.bindings[i];
	count = src.count;
}

void StringMap::expandCapacity() {
	KeyValuePair *oldBindings = bindings;
	capacity *= 2;
	bindings = new KeyValuePair[capacity];
	for (int i = 0; i < count; i++)
		bindings[i] = oldBindings[i];
	delete[] oldBindings;
}