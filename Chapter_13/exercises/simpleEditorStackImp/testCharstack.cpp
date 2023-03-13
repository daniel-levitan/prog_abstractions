#include <iostream>
#include <cassert>
#include <string>
#include "charstack.h"

using namespace std;

int main() {
	cout << "Testing the stack class" << endl;
	cout << "-----------------------" << endl;

	CharStack cstk;
	assert(cstk.size() == 0);
	assert(cstk.isEmpty());
	cstk.push('A');
	assert(!cstk.isEmpty());
	assert(cstk.size() == 1);
	assert(cstk.peek() == 'A');
	cstk.push('B');
	assert(cstk.peek() == 'B');
	assert(cstk.size() == 2);
	assert(cstk.pop() == 'B');
	assert(cstk.size() == 1);
	assert(cstk.peek() == 'A');
	cstk.push('C');
	assert(cstk.size() == 2);
	assert(cstk.pop() == 'C');
	assert(cstk.peek() == 'A');
	assert(cstk.pop() == 'A');
	assert(cstk.size() == 0);
	for (char ch = 'A'; ch <= 'Z'; ch++) {
		cstk.push(ch);
	}
	assert(cstk.size() == 26);
	for (char ch = 'Z'; ch >= 'A'; ch--) {
		assert(cstk.pop() == ch);
	}
	assert(cstk.isEmpty());
	for (char ch = 'A'; ch <= 'Z'; ch++) {
		cstk.push(ch);
	}
	assert(cstk.size() == 26);
	cstk.clear();
	assert(cstk.size() == 0);
	cstk.clear();
	assert(cstk.size() == 0);
	cout << "CharStack unit test succeeded" << endl;

	return 0;
}