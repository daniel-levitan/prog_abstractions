/**
 * File: testCalendar.cpp
 * ----------------------
 * Tests the calendar interface
 */

#include <iostream>
#include <string>
#include "calendar.h"

using namespace std;

int main() {
    
    Date day = Date();
    cout << day.toString() << endl;

    Date day2 = Date(11, MARCH, 2000);
    cout << day2.toString() << endl;

    Date day3 = Date(10, FEBRUARY, 2012);
    cout << day3.toString() << endl;

    cout << "Day " << day3.getDay() << endl;
    cout << "Month " << monthNameToString(day3.getMonth()) << endl;
    cout << "Year " << day3.getYear() << endl;
    return 0;
}