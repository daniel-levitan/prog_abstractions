/**
 * File: stringmap.h
 * -----------------
 * This interface exports a simplified version of the Map class in which
 * the keys and values are always strings.
 */

#ifndef _stringmap_h
#define _stringmap_h

#include <string>
#include "vector.h"

class StringMap {
public:

	/**
	 * Constructor: StringMap 
	 * Usage: StringMap map;
	 * ---------------------
	 * Initializes a new empty map that uses strings as both keys and values.
	 */

	StringMap();

	/**
	 * Destructor: ~StringMap
	 * ----------------------
	 * Frees any heap storage associated with this map.
	 */

	~StringMap();

	/**
	 * Method: get
	 * Usage: string value = map.get(key);
	 * -----------------------------------
	 * Returns the value for key or the empty string, if key is unbound.
	 */

	std::string get(const std::string & key) const;

	/**
	 * Method: put
	 * Usage: map.put(key, value);
	 * ---------------------------
	 * Associates key with value in this map.
	 */

	void put(const std::string & key, const std::string & value);
	
	/**
	 * Notes on the representation
	 * ---------------------------
	 * This version of the StringMap class stores key-value pairs in a Vector.
	 */

	void show() const;
	int getCount() const;

	void clear();
	bool isEmpty() const;

	StringMap(const StringMap & src);
	StringMap & operator=(const StringMap & src);

private:

	struct Cell {
		std::string key;
		std::string value;
		Cell *link;
	};

	static const int INITIAL_BUCKET_COUNT = 13;

	// static const double REHASH_THRESHOLD = 0.7;

	Cell **buckets;
	int nBuckets;
	int count;

	Cell *findCell(int bucket, const std::string & key) const;
	void rehash();
	void deepCopy(const StringMap & src);
};

#endif