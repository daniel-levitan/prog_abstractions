/**
 * File: stringmap.h
 * -----------------
 * This interface exports a simplified version of the Map class in which
 * the keys and values are always strings.
 */

#ifndef _stringmap_h
#define _stringmap_h

#include <string>

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

	void add(const std::string & key, const std::string & value);
	void insert(int index, const std::string & key, const std::string & value);

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

	StringMap(const StringMap & src);
	StringMap & operator=(const StringMap & src);

private:
	
	static const int INITIAL_CAPACITY = 10;
	/**
	 * Type: KeyValuePair
	 * ------------------
	 * This type combines a key and a value into a single structure.
	 */

	struct KeyValuePair {
		std::string key;
		std::string value;
	};

	/* Instance variables */

	KeyValuePair *bindings;
	int capacity;
	int count;

	/* Private function prototypes */
	void deepCopy(const StringMap & src);
	void expandCapacity();

	int findKey(const std::string & key) const;
	int binarySearch(const std::string & key, int p1, int p2) const;
};

#endif