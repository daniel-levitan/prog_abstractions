/**
 * File: fullTestCalendar.cpp
 * --------------------------
 * Tests the calendar interface
 */

#include <iostream>
#include <string>
#include "calendar.h"

using namespace std;

int main() {
    Date d1 = Date(25, FEBRUARY, 2000);
    Date d2 = Date(5, MARCH, 2000);   
	Date d3 = Date(25, FEBRUARY, 2000);
	Date d4 = Date(31, MARCH, 2001);

	// Results of tests 

	cout << "PRINTING TESTS" << endl;
	cout << "--------------" << endl;
    cout << "Test  1 | Operator<< | " << "Expected result: " << "25-Feb-2000 | " << "Result: " << d1 << endl;
	cout << endl;

	cout << "COMPARISON TESTS" << endl;
	cout << "----------------" << endl;
    cout << "Test  2 | Operator== | " << "Expected result: " << "1 | " << "Result: " << (d1 == d3) << endl;
    cout << "Test  3 | Operator!= | " << "Expected result: " << "0 | " << "Result: " << (d1 != d3) << endl;
    cout << "Test  4 | Operator<  | " << "Expected result: " << "1 | " << "Result: " << (d1 < d2) << endl;
    cout << "Test  5 | Operator<  | " << "Expected result: " << "0 | " << "Result: " << (d2 < d1) << endl;
    cout << "Test  6 | Operator<  | " << "Expected result: " << "0 | " << "Result: " << (d1 < d3) << endl;
    cout << "Test  7 | Operator<= | " << "Expected result: " << "1 | " << "Result: " << (d1 <= d2) << endl;
    cout << "Test  8 | Operator<= | " << "Expected result: " << "0 | " << "Result: " << (d2 < d1) << endl;
    cout << "Test  9 | Operator<= | " << "Expected result: " << "1 | " << "Result: " << (d1 <= d3) << endl;
	cout << "Test 10 | Operator>  | " << "Expected result: " << "1 | " << "Result: " << (d2 > d1) << endl;    
	cout << "Test 11 | Operator>  | " << "Expected result: " << "0 | " << "Result: " << (d1 > d2) << endl;    
	cout << "Test 12 | Operator>  | " << "Expected result: " << "0 | " << "Result: " << (d1 > d1) << endl;    
	cout << "Test 13 | Operator>= | " << "Expected result: " << "1 | " << "Result: " << (d2 >= d1) << endl;    
	cout << "Test 14 | Operator>= | " << "Expected result: " << "0 | " << "Result: " << (d1 >= d2) << endl;    
	cout << "Test 15 | Operator>= | " << "Expected result: " << "1 | " << "Result: " << (d1 >= d1) << endl;   
	cout << endl;

	cout << "ADDING TESTS" << endl;
	cout << "------------" << endl;
	cout << "Test 16 | Operator+  | " << "Expected result: " << "26-Feb-2000 | " << "Result: " << (d1 + 1) << endl;   
	cout << "Test 17 | Operator+  | " << "Expected result: " << " 1-Apr-2001 | " << "Result: " << (d4 + 1) << endl;   
	cout << endl;

	cout << "INCREMENT TESTS" << endl;
	cout << "---------------" << endl;
	cout << "Test 18 | Operator++ | " << "Expected result: " << "31-Mar-2001   | " << "Result: " << (d4++) << endl;   
	cout << "Test 19 | ++Operator | " << "Expected result: " << " 2-Apr-2001   | " << "Result: " << (++d4) << endl;   
	cout << "Test 20 | Operator-- | " << "Expected result: " << " 2-Apr-2001   | " << "Result: " << (d4--) << endl;   
	cout << "Test 21 | Operator-- | " << "Expected result: " << "31-Mar-2001   | " << "Result: " << (--d4) << endl;   
	cout << endl;

	cout << "ASSIGNMENT TESTS" << endl;
	cout << "----------------" << endl;
	d4 += 4;
	cout << "Test 22 | Operator+= | " << "Expected result: " << " 4-Apr-2001   | " << "Result: " << d4 << endl;
	d4 -= 3;
	cout << "Test 23 | Operator-= | " << "Expected result: " << " 1-Apr-2001   | " << "Result: " << d4 << endl;
	cout << endl;
	
	cout << "DIFFERENCE TESTS" << endl;
	cout << "----------------" << endl;
	cout << endl;

    return 0;
}















