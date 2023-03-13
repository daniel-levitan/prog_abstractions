/**
 * File: ex_8_find_easter.cpp
 * -----------------------
 * This program solves exercise #8 of the new book.
 * 
 * Write a program to find the Easter date for year in the 
 * reference parameters month and day
 * 
 * I. Divide the number of the year for which one wishes to calculate Easter
 * by 19, by 4, and by 7, and call the remainders of these divisions a, b, and c, 
 * respectively.
 * 
 * If the division is even, set the remainder to 0; the quotients
 *  are not taken into account. Precisely the same is true of the following divisions.
 * ==> THIS DIDNT WORK
 * 
 * II. Divide the value 19a + 23 by 30 and call the remainder d.
 * 
 * III. Finally, divide 2b + 4c + 6d + 3, or 2b + 4c + 6d + 4, choosing the
 * former for years between 1700 and 1799 and the latter for years between 
 * 1800 and 1899, by 7 and call the remainder e.
 * 
 * Then Easter falls on March 22 + d + e, or when d + e is greater than 9, 
 * on April d + e – 9.
 */

#include <iostream>
#include <string>
#include "../../libraries/simpio.h"
#include "../../libraries/strlib.h"

using namespace std;

void findEaster(int year, string & month, int & day);

int main() {
	string month;
	// int month;
	int day;

	cout << "Get easter month and day" << endl;
	int year = getInteger("Insert a year: ");
	findEaster(year, month, day);
	cout << "Month and Day: " << month << ", " << day << endl;

	return 0;
}

void findEaster(int year, string & month, int & day) {	
	// Step 1
	int a = year % 19;
	// if ((year % 2) == 0) a = 0;
	int b = year % 4;
	// if ((year % 2) == 0) b = 0;
	int c = year % 7;
	// if ((year % 2) == 0) c = 0;

	// Step 2
	int d = (19 * a + 23) % 30;

	// Step 3
	int e;
	if ((year >= 1700) && (year <= 1799)) {
		e = (2 * b + 4 * c + 6 * d + 3) % 7;
	}

	if ((year >= 1800) && (year <= 1899)) {
		e = 2 * b + 4 * c + 6 * d + 4;
	}	

	if ((year >= 1700) && (year <= 1899)) {
		if ((d + e) > 9) {
			month = "April";
			day = d + e - 9;
		} else {
			month = "March";
			day = 22 + d + e;
		}
	} else {
		month = "No month";
		day = -1;
	}



}