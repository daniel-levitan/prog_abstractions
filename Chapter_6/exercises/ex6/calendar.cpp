/**
 * File: calendar.cpp
 * ------------------
 * Implements the calendar interface
 */

#import <iostream>
#import <sstream>
#import <string>
#import "calendar.h"
#import "../../../libraries/error.h"

/**
 * Constructors: Date
 * Usage:		 Date Date();
 * 				 Date Date(monthName month, int day, int year);
 *				 Date Date(int day, monthName month, int year);
 * ---------------------------------------------------------------
 * Initializes a date object. The default constructor initializes the
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
	return integerToString(day) + "-" + 
	       monthNameToString(month) + "-" + 
	       integerToString(year); 
}

// Overloadings
std::ostream & operator<<(std::ostream & os, Date date) {
	return os << date.toString();
}

bool Date::operator==(Date date) {
	return day == date.day && month == date.month && year == date.year;
}

bool Date::operator!=(Date date) {
	return !operator==(date);
}

bool Date::operator>(Date date) {
	if (year > date.year)
		return true;
	if (year < date.year)
		return false;

	// Year is equal
	if (month > date.month)
		return true;
	if (month < date.month)
		return false;

	// Month is equal
	if (day > date.day)
		return true;
	if (day < date.day)
		return false;
	return false;
}

bool Date::operator>=(Date date) {
	if (operator==(date))
		return true;
	else
		return operator>(date);
}

bool Date::operator<(Date date) {
	// if (year == date.year) && 
	   // (month == date.month) &&
	   // (day == datee.day)
	   // return false;

	if (year < date.year)
		return true;
	if (year > date.year)
		return false;

	if (month < date.month)
		return true;
	if (month > date.month)
		return false;

	if (day < date.day)
		return true;
	if (day > date.day)
		return false;
	return false;
}

bool Date::operator<=(Date date) {
	if (operator==(date))
		return true;
	else
		return operator<(date);
}

Date Date::operator+(int n) {
	int newDay = day + n;
	monthName newMonth = month;
	int newYear = year;
	
	while (newDay > getMonthExtension(newMonth, year)) {
		newDay -= getMonthExtension(newMonth, year);
		newMonth = monthName((newMonth + 1) % 12);
		if (newMonth == JANUARY) newYear++;
	}
	return Date(newDay, newMonth, newYear);
}

Date Date::operator-(int n) {
	int newDay = day - n;
	monthName newMonth = month;
	int newYear = year;

	while (newDay < 1) {
		if ((newMonth - 1) < 0)
			newMonth = monthName((newMonth + 11));
		else
			newMonth = monthName(newMonth - 1);
 
 		newDay += getMonthExtension(newMonth, year);
		if (newMonth == DECEMBER) newYear--;
	}
	return Date(newDay, newMonth, newYear);	
}

int Date::operator-(Date date) {
	if (date >= *this)
		error("ERROR: The lefthand side should be bigger than the righthand side.");
	int total = 0;

	// Year and Month are the same
	if ((year == date.year) && (month == date.month)) 
		return day - date.day + 1;

	// Year is the same
	if (year == date.year) {
		for (int i = date.month + 1; i < month; i++) 
			total += getMonthExtension(monthName(i), date.year);
		// Lower month
		total += getMonthExtension(date.month, date.year) - date.day + 1; 
		// Higher month
		total += day;
		return total;
	}

	// Year is not the same
	if ((year - date.year) > 2) {
		for (int i = date.year + 1; i < year; i++) 
			isLeapYear(i) ? total += 366 : total += 365;	
	}

	for (int i = date.month; i < 12; i++) 
		total += getMonthExtension(monthName(i), date.year);
	total = total - date.day;
	
	for (int i = 0; i < month; i++) 
		total += getMonthExtension(monthName(i), year);
	total += day;
	return total;
}

Date& Date::operator+=(int n) {
	day += n;
	
	while (day > getMonthExtension(month, year)) {
		day -= getMonthExtension(month, year);
		month = monthName((month + 1) % 12);
		if (month == JANUARY) year++;
	}
	return *this;
}

Date& Date::operator-=(int n) {
	day -= n;
	while (day < 1) {
		if ((month - 1) < 0)
			month = monthName((month + 11));
		else
			month = monthName(month - 1);
 
 		day += getMonthExtension(month, year);
		if (month == DECEMBER) year--;
	}
	return *this;
}

// prefix
Date& Date::operator++() {
	day++;
	if (day > getMonthExtension(month, year)) {
		day -= getMonthExtension(month, year);
		month = monthName((month + 1) % 12);
		if (month == JANUARY) year++;
	}
	return *this;
}

Date& Date::operator--() {
	day--;
	if (day < 1) {
		if ((month - 1) < 0)
			month = monthName((month + 11));
		else
			month = monthName(month - 1);		
		day += getMonthExtension(month, year);
		if (month == DECEMBER) year--;	
	}
	return *this;
}

// postfix
Date Date::operator++(int) {
	Date returnDate = Date(day, month, year);
	day++;
	if (day > getMonthExtension(month, year)) {
		day -= getMonthExtension(month, year);
		month = monthName((month + 1) % 12);
		if (month == JANUARY) year++;
	}
	return returnDate;
}

Date Date::operator--(int) {
	Date returnDate = Date(day, month, year);
	day--;
	if (day < 1) {
		if ((month - 1) < 0)
			month = monthName((month + 11));
		else
			month = monthName(month - 1);		
		day += getMonthExtension(month, year);
		if (month == DECEMBER) year--;	
	}
	return returnDate;
}

// Auxiliary functions

std::string integerToString(int n) {
	std::ostringstream stream;
	stream << n;
	return stream.str();
}

bool isLeapYear(int year) {
	return ((year % 4 == 0) && (year % 100 != 0))
		    || (year % 400 == 0);
}

int getMonthExtension(monthName month, int year) {
	switch (month) {
		case APRIL: case JUNE: case SEPTEMBER: case NOVEMBER:
			return 30;
		case FEBRUARY:
			return (isLeapYear(year)) ? 29 : 28;
		default:
			return 31;
	}	
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

