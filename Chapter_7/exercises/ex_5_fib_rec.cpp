/**
 * File: ex_5_fib_rec.cpp
 * ----------------------
 * Iterative Fibonacci
 * 0 1 2 3 4 5 6  7
 * 0 1 1 2 3 5 8 13 
 */

#include <iostream>

using namespace std;


int fibRec(int n);


int main() {
	cout << fibRec(0) << endl;
	cout << fibRec(1) << endl;
	cout << fibRec(2) << endl;
	cout << fibRec(3) << endl;
	cout << fibRec(4) << endl;
	cout << fibRec(5) << endl;
	cout << fibRec(6) << endl;
	return 0;
}

int fibRec(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;

	int prev = 0;
	int actual = 1;
	int temp = 0;
	
	int i = 1;
	while (i < n) {
		temp = prev + actual;
		prev = actual;
		actual = temp;
		i++;
	}
	return actual;
}