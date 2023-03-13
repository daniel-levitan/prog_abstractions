/**
 * File: ex_2_raiseToPower.cpp
 * -------------------------
 * rais
 */

#include <iostream>
#include <string>

using namespace std;

int raiseToPower(int n, int k);

int main() {
	cout << raiseToPower(2, 3) << endl;	
	cout << raiseToPower(3, 3) << endl;	
	return 0;
}

int raiseToPower(int n, int k) {
	if (k == 0)
		return 1;
	else
		return n * raiseToPower(n, k - 1);
	
}