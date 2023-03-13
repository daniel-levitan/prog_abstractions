/**
 * File: ex_15_coin_flip.cpp
 * -----------------------
 * This program solves exercise #15 of the new book.
 */

#include <iostream>
#include "../../libraries/random.h"

using namespace std;

int main() {    
    int flips = 0;
	int headsSoFar = 0;


	while (headsSoFar != 3) {
		if (randomChance(0.5)) {
			headsSoFar++;
			cout << "heads" << endl;
		} else {
			headsSoFar = 0;
			cout << "tails" << endl;
		}
		flips++;
	}
	cout << "It took " << flips << " flips to get 3 consecutive heads" << endl;
    return 0;
}