/**
 * File: calendar.h
 * ----------------
 * Defines the interface for the calendar class
 */

#ifndef _date_h
#define _date_h


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

    Date operator+(int n);
    Date operator-(int n);

    // The expression d1 - d2, which returns how many days separate d1 and d2
    // The shorthand assignment operators += and -= with an integer on the right
    // The ++ and -- operators in both their prefix and suffix form.


private:
    int day;
    monthName month;
    int year;
};

std::string monthNameToString(monthName month);
std::string integerToString(int n);
int monthExtension(monthName month, int year);

std::ostream & operator<<(std::ostream & os, Date date);



#endif
