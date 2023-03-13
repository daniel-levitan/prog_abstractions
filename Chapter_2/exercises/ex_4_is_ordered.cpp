/*
 * File: ex_4_is_ordered.cpp
 * -------------------------
 * This program checks is an array is sorted in nondecreasing order.
 * 
 * Write a predicate function IsSorted(array, n) that takes an integer array 
 * and its effective size as parameters and returns true if the array 
 * is sorted in nondecreasing order.
 */

#include <iostream>
#include "../../libraries/simpio.h"

using namespace std;

bool isSorted(int array[], int n);
int GetElement(int index);
void ReadAllElements(int array[], int n);

int main() {
	
	string prompt_size = "Enter the size of the array: ";
    int n = getInteger(prompt_size);

    int array[n];
	ReadAllElements(array, n);
	bool result = isSorted(array, n);
	cout << "The array is " << result << endl;

	return 0;
}

bool isSorted(int array[], int n) {

	int element = INT_MIN; // This is the biggest negative number

	for (int i = 0; i < n; i++) {
		if (array[i] < element) {
			return false;
		}
		element = array[i];
		
	}
	return true;
}



void ReadAllElements(int array[], int n) {
    for (int i = 0; i < n; i++) {
        array[i] = GetElement(i + 1);
    }
}

int GetElement(int index) {
    string prompt = "Element #";
    while (true) {
        prompt += to_string(index) + ": ";
        int element = getInteger(prompt);
        return element;
    } 
}
