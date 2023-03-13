/**
 * File: ex_4_gcd.cpp
 * -----------------------
 * greatest common divisor 
 * 
 * If x is evenly divisible by y, then y is the greatest common divisor.
•* Otherwise, the greatest common divisor of x and y is always equal to the
 * greatest common divisor of y and the remainder of x divided by y.
 * 
 */

#include <iostream>
#include <string>

using namespace std;

int gcd(int a, int b);

int main() {
	int a = 4;
	int b = 2;
	cout << gcd(105, 15) << endl;
	cout << gcd(15, 105) << endl;
	return 0;
}

int gcd(int x, int y) {
	if ((x % y) == 0)
		return y;
	else {
		return gcd(y, x % y);
	}
}