/**
 * Implementation notes: hashCode
 * ------------------------------
 * 
 * 
 */
#include "hashcode.h"

const int HASH_SEED = 5381;
const int HASH_MULTIPLIER = 33;
const int HASH_MASK = unsigned(-1) >> 1;

int hashCode(const std::string & str) {
	unsigned hash = HASH_SEED;
	int n = str.length();
	for (int i = 0; i < n; i++) {
		hash = HASH_MULTIPLIER * hash + str[i];
	}
	return int(hash & HASH_MASK);
}