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

	bool operator==(Date date);	
	bool operator!=(Date date);	
	bool operator>(Date date);
	bool operator>=(Date date);
	bool operator<(Date date);
	bool operator<=(Date date);

	// Date operator+(int n);
	Date operator+(int n);
	Date operator-(int n);
	int operator-(Date date); // pending -> must develop the logic first
	Date& operator+=(int n); 
	Date& operator-=(int n); 
	Date& operator++(); // prefix
	Date& operator--(); // prefix
	Date operator++(int); // postfix
	Date operator--(int); // postfix


private:
	int day;
	monthName month;
	int year;
};

std::string monthNameToString(monthName month);
std::string integerToString(int n);
int getMonthExtension(monthName month, int year);
bool isLeapYear(int year);

std::ostream & operator<<(std::ostream & os, Date date);



#endif