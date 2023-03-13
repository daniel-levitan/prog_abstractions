/**
 * File: calendar.h
 * ----------------
 * Defines the interface for the calendar class
 */

#ifndef _calendar_h
#define _calendar_h


enum monthName { JANUARY,
				 FEBRUARY,
				 MARCH,
				 APRIL,
				 MAY,
				 JUNE,
				 JULY,
				 AUGUST,
				 SEPTEMBER,
				 OCTOBER,
				 NOVEMBER,
				 DECEMBER
};

class Date {
public:
	Date();
	Date(monthName monthc, int dayc, int yearc);
	Date(int dayc, monthName monthc, int yearc);

	int getDay();
	monthName getMonth();
	int getYear();

	std::string toString();

private:
	int day;
	monthName month;
	int year;
};

std::string monthNameToString(monthName month);
std::string integerToString(int n);

#endif