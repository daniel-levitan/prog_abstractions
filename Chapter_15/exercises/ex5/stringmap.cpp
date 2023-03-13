#include <iostream>
#include <string>
#include "hashcode.h"
#include "stringmap.h"
using namespace std;

StringMap::StringMap() {
	nBuckets = INITIAL_BUCKET_COUNT;
	count = 0;
	buckets = new Cell*[nBuckets];
	for (int i = 0; i < nBuckets; i++) 
		buckets[i] = NULL;
}

StringMap::~StringMap() {
	// for (int i = 0; i < nBuckets; i++) {
	// 	Cell *cp = buckets[i];
	// 	while (cp != NULL) {
	// 		Cell *oldCell = cp;
	// 		cp = cp->link;
	// 		delete oldCell;
	// 	}
	// }
	clear();
}

string StringMap::get(const string & key) const {
	int bucket = hashCode(key) % nBuckets;
	Cell *cp = findCell(bucket, key);
	return (cp == NULL) ? "" : cp->value;
}

void StringMap::put(const string & key, const string & value) {
	int bucket = hashCode(key) % nBuckets;
	Cell *cp = findCell(bucket, key);
	if (cp == NULL) {
		cp = new Cell;
		cp->key = key;
		cp->link = buckets[bucket];
		buckets[bucket] = cp;
		count ++;
	}
	cp->value = value;

	if (count / float(nBuckets) > 0.7)
		rehash();
}

void StringMap::show() const {
	for (int i = 0; i < nBuckets; i++) {
		Cell *cp = buckets[i];
		if (cp != NULL) {
			cout << i << "  ";
			while (cp != NULL) {
				cout << cp->value;
				if (cp->link != NULL)
					cout << "->";
				cp = cp->link;
			}
			cout << endl;
		}
	}
}

int StringMap::getCount() const {
	return count;
}


StringMap::Cell *StringMap::findCell(int bucket, const string & key) const {
	Cell *cp = buckets[bucket];
	while (cp != NULL && key != cp->key)
		cp = cp->link;
	return cp;
}

bool StringMap::isEmpty() const {
	return count == 0;
}

void StringMap::clear() {
	// if (!isEmpty()) {
	// }

	for (int i = 0; i < nBuckets; i++) {
		Cell *cp = buckets[i];
		while (cp != NULL) {
			Cell *oldCell = cp;
			cp = cp->link;
			delete oldCell;
		}
	}
}



StringMap::StringMap(const StringMap & src) { 
	deepCopy(src);
}

StringMap & StringMap::operator=(const StringMap & src) { 
	if (this != &src) {
		clear();
		deepCopy(src);
	}
	return *this; 
}
void StringMap::rehash() {
	cout << "Rahash " << count / float(nBuckets) << endl;
	cout << "Antes " << endl;
    show();

 	int newCount = count;
 	int newnBuckets = nBuckets * 2;

 	Cell **newBuckets;
 	newBuckets = new Cell*[newnBuckets];
	for (int i = 0; i < newnBuckets; i++) 
		newBuckets[i] = NULL;

	for (int i = 0; i < nBuckets; i++) {
		for (Cell *cp = buckets[i]; cp != NULL; cp = cp->link) {
			int bucket = hashCode(cp->key) % newnBuckets;
			Cell *ncp = new Cell;
			ncp->key = cp->key;
			ncp->value = cp->value;

			if (newBuckets[bucket] == NULL) {
				ncp->link = NULL;
				newBuckets[bucket] = ncp;
			} else {
				Cell *start = newBuckets[bucket];
				ncp->link = start;
				newBuckets[bucket] = ncp;
			}

		}

		
		// Cell *tail = NULL;
		// for (Cell *cp = buckets[i]; cp != NULL; cp = cp->link) {
		// 	int bucket = hashCode(cp->key) % newnBuckets;
		// 	Cell *ncp = new Cell;
		// 	ncp->key = cp->key;
		// 	ncp->value = cp->value;
		// 	if (tail == NULL) 
		// 		newBuckets[bucket] = ncp;
		// 	else
		// 		tail->link = ncp;
		// }
		// if (tail != NULL) tail->link = NULL;
	}
	clear();


	count = newCount;
	nBuckets = newnBuckets;
	buckets = newBuckets;

	cout << "Depois " << endl;
    show();
}

void StringMap::deepCopy(const StringMap & src) {
	count = src.count;
	nBuckets = src.nBuckets;
	buckets = new Cell*[nBuckets];

	for (int i = 0; i < nBuckets; i++) 
		buckets[i] = NULL;
	
	for (int i = 0; i < src.nBuckets; i++) {
		Cell *tail = NULL;
		// Esse loop só olha que tem algo
		for (Cell *cp = src.buckets[i]; cp != NULL; cp = cp->link) {
			Cell *ncp = new Cell;
			ncp->key = cp->key;
			ncp->value = cp->value;

			if (tail == NULL)
				buckets[i] = ncp;
			else
				tail->link = ncp;
			tail = ncp;
		}
		if (tail != NULL) tail->link = NULL;
	}
}




