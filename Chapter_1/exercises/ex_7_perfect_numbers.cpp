/*
 * File: ex_7_perfect_numbers.cpp
 * ------------------------------
 * This program solves exercise #7.
 *
 * Write a predicate function IsPerfect that takes an integer n 
 * and returns true if n is perfect, and false otherwise.
 * 
 * Perfect numbers are those which the sum of their proper divisors are
 * equal to the number. Ex. 6 has divisors 1, 2, and 3 that sum 6.
 * 
 * A proper divisor of N is any divisor less than N itself
 * 
 */

#include <iostream>

using namespace std;

const int MAX = 9999;

bool isDivisor(int divisor, int n);
bool isPerfect(int n);

int main() {

	for (int i = 1; i < MAX; i++)
		if (isPerfect(i)) cout << i << " is perfect!" << endl;	
	
	// if (isPerfect(n))
	// 	cout << n << " is perfect!" << endl;
	// else
	// 	cout << n << " is not perfect :(" << endl;

	return 0;
}

bool isDivisor(int divisor, int n) {	
	if ((n % divisor) == 0) return true;
	return false;
}

bool isPerfect(int n) {
	int sum = 0;
	for (int i = 1; i < n; i++){
		if (isDivisor(i, n)) sum += i;
	}

	if (sum == n) return true;
	return false;
}