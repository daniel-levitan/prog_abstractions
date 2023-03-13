/**
 * File: testRational.cpp
 * Test of the rational class
 * 
 */

#include <iostream>
#include "rational.h"

using namespace std;

int main() {
	Rational r0 = Rational();
	Rational r1 = Rational(-3, 4);
	Rational r2 = Rational(1, -2);
	Rational r3 = Rational(3, 4);
	Rational r4 = Rational(1, 2);
	Rational r5 = Rational(1, 2);
	Rational r6 = Rational(2, 6);
	

	// Rational r4 = Rational(1, 0);

	cout << "r0 | " << r0 << endl;
	cout << "r1 | " << r1 << endl;
	cout << "r2 | " << r2 << endl;
	cout << "r3 | " << r3 << endl;
	cout << "r4 | " << r4 << endl;
	cout << "r5 | " << r5 << endl;
	cout << "r6 | " << r6 << endl;
	cout << endl;

	cout << "COMPARISONS" << endl;
	cout << "-----------" << endl;
	cout << "Test  1 | Operator== | " << "Expected result: " << "1 | " << "Result: " << (r4 == r5) << endl;
	cout << "Test  2 | Operator== | " << "Expected result: " << "0 | " << "Result: " << (r0 == r1) << endl;
	cout << "Test  3 | Operator!= | " << "Expected result: " << "1 | " << "Result: " << (r1 != r2) << endl;
	cout << "Test  4 | Operator!= | " << "Expected result: " << "0 | " << "Result: " << (r4 != r5) << endl;
	cout << "Test  5 | Operator>  | " << "Expected result: " << "1 | " << "Result: " << (r3 > r4) << endl;
	cout << "Test  6 | Operator>  | " << "Expected result: " << "0 | " << "Result: " << (r4 > r3) << endl;
	cout << "Test  7 | Operator>  | " << "Expected result: " << "0 | " << "Result: " << (r4 > r4) << endl;
	cout << "Test  8 | Operator>= | " << "Expected result: " << "1 | " << "Result: " << (r3 > r4) << endl;
	cout << "Test  9 | Operator>= | " << "Expected result: " << "0 | " << "Result: " << (r4 > r3) << endl;
	cout << "Test 10 | Operator>= | " << "Expected result: " << "1 | " << "Result: " << (r4 > r4) << endl;
	cout << "Test 11 | Operator<  | " << "Expected result: " << "1 | " << "Result: " << (r4 < r3) << endl;
	cout << "Test 12 | Operator<  | " << "Expected result: " << "0 | " << "Result: " << (r3 < r4) << endl;
	cout << "Test 13 | Operator<  | " << "Expected result: " << "0 | " << "Result: " << (r3 < r3) << endl;
	cout << "Test 14 | Operator<= | " << "Expected result: " << "1 | " << "Result: " << (r4 <= r3) << endl;
	cout << "Test 15 | Operator<= | " << "Expected result: " << "0 | " << "Result: " << (r3 <= r4) << endl;
	cout << "Test 16 | Operator<= | " << "Expected result: " << "1 | " << "Result: " << (r3 <= r3) << endl;

	cout <<  endl;

	cout << "OPERATIONS" << endl;
	cout << "----------" << endl;
	cout << "Test 17 | Operator+  | " << "Expected result: " << " 5/4 | " << "Result: " << (r3 + r4) << endl;
	cout << "Test 18 | Operator+  | " << "Expected result: " << " 1/1 | " << "Result: " << (r4 + r5) << endl;
	cout << "Test 19 | Operator-  | " << "Expected result: " << " 1/4 | " << "Result: " << (r3 - r4) << endl;
	cout << "Test 20 | Operator-  | " << "Expected result: " << "-1/4 | " << "Result: " << (r1 - r2) << endl;
	cout << "Test 21 | Operator*  | " << "Expected result: " << " 3/8 | " << "Result: " << (r3 * r4) << endl;
	cout << "Test 22 | Operator*  | " << "Expected result: " << " 1/6 | " << "Result: " << (r4 * r6) << endl;
	cout << "Test 23 | Operator/  | " << "Expected result: " << " 3/2 | " << "Result: " << (r3 / r4) << endl;
	cout << "Test 24 | Operator/  | " << "Expected result: " << "-9/4 | " << "Result: " << (r1 / r6) << endl;
	r5 += r6;
	cout << "Test 25 | Operator+= | " << "Expected result: " << " 5/6 | " << "Result: " << r5 << endl;
	r5 -=r6;
	cout << "Test 26 | Operator-= | " << "Expected result: " << " 1/2 | " << "Result: " << r5 << endl;
	r3 *= r4;
	cout << "Test 27 | Operator*= | " << "Expected result: " << " 3/8 | " << "Result: " << r3 << endl;
	r3 /= r4;
	cout << "Test 28 | Operator/= | " << "Expected result: " << " 3/4 | " << "Result: " << r3 << endl;
	cout << "Test 29 | ++Operator | " << "Expected result: " << " 7/4 | " << "Result: " << ++r3 << endl;
	r3 = Rational(3, 4);
	cout << "Test 30 | Operator++ | " << "Expected result: " << " 3/4 | " << "Result: " << r3++ << endl;
	cout << "Test 30 | Operator++ | " << "Expected result: " << " 7/4 | " << "Result: " << r3 << endl;
	cout << "Test 31 | --Operator | " << "Expected result: " << " 3/4 | " << "Result: " << --r3 << endl;
	r3 = Rational(3, 4);
	cout << "Test 32 | Operator-- | " << "Expected result: " << " 3/4 | " << "Result: " << r3-- << endl;
	cout << "Test 32 | Operator-- | " << "Expected result: " << "-1/4 | " << "Result: " << r3 << endl;
	
	cout <<  endl;




	return 0;
}