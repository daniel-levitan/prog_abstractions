/**
* File: Permutations.cpp
* ----------------------
* This file generates all permutations of an input string.
*/

#include <iostream>
#include <string>

using namespace std;

void listPermutations(string str);
void permutations(string &str, int index);

int main() {
	string str = "abc";
	cout << "The permutations of \"" << str << "\" are:" << endl;
	listPermutations(str);	

	return 0;
}


/**
 * Functions permutations
 * Usage: void perm = permutations(str, int);
 * ----------------------------------------------------------
 * a) At each level, pass the entire string along with an index that indicates
 * where the permutation process starts. Characters in the string before this
 * index stay where they are; characters at or after that position must go
 * through all their permutations.
 * 
 * b) The simple case occurs when the index reaches the end of the string.
 * 
 * c) The recursive case operates by swapping the character at the index
 * position with every other character in the string and then generating every
 * permutation starting with the next higher index and then swapping the
 * characters back to ensure that the original order is restored.
 * 
 */ 

void permutations(string &str, int index) {
	
	if (index == str.length()) {
		cout << str << endl;
	} else {
		for (int i = index + 1; i < str.length(); i++) {
			char tmp = str[index];
			str[index] = str[i];
			str[i] = tmp;

			permutations(str, index + 1);
			cout << str << endl;
						
			str[i] = str[index];
			str[index] = tmp;
			permutations(str, index + 1);
		}
	}
}


/**
* Function: listPermutations
* Usage: void permutations = listPermutations(str);
* ------------------------------------------------------------
* Prints all permutations of the specified string.
* 
*/

void listPermutations(string str) {
	permutations(str, 0);
}








