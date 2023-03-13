/**
 * File: ex_1_formatting.cpp
 * -------------------------
 * 
 * Formatting outputs
 */

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
	cout << " theta | sin(theta) | cos(theta) " << endl;
	cout << "-------+------------+------------" << endl;	
	for (int i = -90; i <= 90; i +=15) {
		cout << right << setw(5) << i << "  |" << fixed
		     << right << setw(11) << setprecision(7) << sin(i / 180.0 * M_PI) << " |"
		     << right << setw(11) << setprecision(7) << cos(i / 180.0 * M_PI) 
		 << endl;
	}	
	return 0;
}


// setw(n),setprecision(digits),andsetfill(ch)