/** 
 * File: loopTest.cpp
 * ------------------
 * 
 * Testing loops and breaks
 */

#include <iostream>

using namespace std;

const int LOOPS = 6;

int main() {

	int count = 0;

	while (count < LOOPS) {
		cout << "Inside while" << endl;

		for (int i = 0; i < LOOPS / 2; i++) {
			cout << "While & for (" << count << ", " << i << ")" << endl; 
			// if (i == 1)
				// break;
		}

		count++;
	}

	return 0;
}