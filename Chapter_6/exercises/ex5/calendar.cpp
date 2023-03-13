/**
 * File: calendar.cpp
 * ------------------
 * Implements the calendar interface
 */

#import <iostream>
#import <sstream>
#import <string>
#import "calendar.h"




/**
 * Constructors: Date
 * Usage:		 cal Date();
 * 				 cal Date(monthName month, int day, int year);
 *				 cal Date(int day, monthName month, int year);
 * ---------------------------------------------------------------
 * Initializes a calendar object. The default constructor initializes the
 * object to JULY, 20, 1969. The other two takes those as parameters.
 */

Date::Date() {
	day = 1;
	month = JANUARY;
	year = 1900;
}

Date::Date(monthName monthc, int dayc, int yearc) {
	day = dayc;
	month = monthc;
	year = yearc;
}

Date::Date(int dayc, monthName monthc, int yearc) {
	day = dayc;
	month = monthc;
	year = yearc;
}

int Date::getDay() {
	return day;
}

monthName Date::getMonth() {
	return month;
}

int Date::getYear() {
	return year;
}

std::string Date::toString() {
	// string monthStr = month

	return integerToString(day) + "-" + 
	       monthNameToString(month) + "-" + 
	       integerToString(year); 
	// return 
}





// Auxiliary functions

std::string integerToString(int n) {
	std::ostringstream stream;
	stream << n;
	return stream.str();
}

std::string monthNameToString(monthName month) {
	switch (month) {
		case JANUARY:
			return "Jan";
		case FEBRUARY:
			return "Feb";
		case MARCH:
			return "Mar";
		case APRIL:
			return "Apr";
		case MAY:
			return "May";
		case JUNE:
			return "Jun";
		case JULY:
			return "Jul";
		case AUGUST:
			return "Aug";
		case SEPTEMBER:
			return "Sep";
		case OCTOBER:
			return "Oct";
		case NOVEMBER:
			return "Nov";
		case DECEMBER:
			return "Dec";
		default:
			return "No Month"; // error
	}
}