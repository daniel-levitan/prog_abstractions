/**
 * File: ex_13_half_life.cpp
 * -----------------------
 * This program solves exercise #13 of the new book.
 */

#include <iostream>
#include <string>
#include "../../libraries/random.h"

using namespace std;

const int START_SIZE = 10000;

// int halfLife(int& sampleSize);

int main() {
	int numOfAtoms = START_SIZE;
	int year = 0;
	
	cout << "There are " << numOfAtoms << " atoms initially." << endl;			
	int remaining = numOfAtoms;

	while (remaining > 0) {	
		for (int i = 0; i < numOfAtoms; i++) {
			if (randomChance(0.5)) remaining--;
		}
		numOfAtoms = remaining;
		year++;
		cout << "There are " << numOfAtoms << " atoms at the end of year " << year << "." << endl;	
	}

	// int remainingAtoms = START_SIZE;
	// year = 0;
	// while (halfLife(remainingAtoms)) {
	// 	cout << "There are " << remainingAtoms << " atoms at the end of year " 
	// 		 << year << "." << endl;	
	// 	year++;		
	// 	// break;
	// }	

 //    cout << "There are " << remainingAtoms << " atoms at the end of year "
 //         << ++year << "." << endl;

	return 0;
}

// int halfLife(int &sampleSize) {
//     int startSize = sampleSize;
//     for (int i = 0; i < startSize; i++) {
//     	if (randomChance(0.5)) sampleSize--;
//     }    
//     return sampleSize;
// }