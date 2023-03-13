/*
 * File: ex_8_prime_fact.cpp
 * -------------------------
 * This program solves exercise #8.
 *
 * Write a program to display the prime factorization of a number n
 * 
 */

#include <iostream>
#include <string>
#include "../../libraries/simpio.h"

using namespace std;

bool isPrime(int n);
int nextPrime(int start);

int main(){
	string prompt = "Enter a number: ";
	int n = getInteger(prompt);
	int currentPrime = 2;
	string expression = "";

	while (n > 1) {
		if ((n % currentPrime) == 0) {
			n /= currentPrime;
			expression += to_string(currentPrime) + " x ";
		}
		else {
			currentPrime = nextPrime(currentPrime);
		}
	}

	cout << "Expression " << expression.substr(0, expression.length() - 2) << endl; 
	// cout << "Start is " << n << " next prime is " << nextPrime(n) << endl;

	return 0;
}

bool isPrime(int n){
	if ((n == 0) or (n == 1)) return false;

	int i = 2;
	while (i < n){
		if ((n % i) == 0) return false; 
		i++;
	}
	return true;
}

int nextPrime(int start){
	while (true) if (isPrime(++start)) break;
	return start;
}