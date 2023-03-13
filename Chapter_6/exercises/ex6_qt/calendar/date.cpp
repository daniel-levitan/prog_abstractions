/**
 * File: calendar.cpp
 * ------------------
 * Implements the calendar interface
 */

#import <iostream>
#import <sstream>
#import <string>
#import "date.h"


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

    while (newDay > monthExtension(newMonth, year)) {
        newDay -= monthExtension(newMonth, year);
        newMonth = monthName((newMonth + 1) % 12);
        if (newMonth == JANUARY) newYear++;
    }
    return Date(newDay, newMonth, newYear);
}


Date Date::operator-(int n) {
    int newDay = day - n;
    monthName newMonth = month;
    int newYear = year;

    std::cout << "New day " << newDay << std::endl;

//    while (newDay < 1) {
//        if ((newMonth - 1) < 0)
//            newMonth = monthName((newMonth + 12));
//        else
//            newMonth = monthName(newMonth - 1);
//        newDay += monthExtension(newMonth, year);
//        if (newMonth == DECEMBER) newYear--;
//    }
    do {
        if ((newMonth - 1) < 0)
            newMonth = monthName((newMonth + 12));
        else
            newMonth = monthName(newMonth - 1);
        newDay += monthExtension(newMonth, year);
        if (newMonth == DECEMBER) newYear--;

    } while (newDay < 1);

    return Date(newDay, newMonth, newYear);
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

int monthExtension(monthName month, int year) {
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

