/**
 * File: testCalendar.cpp
 * ----------------------
 * Tests the calendar interface
 */

#include <iostream>
#include <string>
#include "console.h"
#include "date.h"

using namespace std;

int main() {

    Date day = Date(15, FEBRUARY, 2000);

    cout << "Date " << day << endl;
    // int n = 60;
    // cout << "  => " << (day + n) << endl;

    int n = 57;
    cout << "  => " << (day - n) << endl;

    // cout << day2 << " >= " << day3 << ": " << (day2 >= day3) <<  endl;
    // cout << day2 << " <= " << day3 << ": " << (day2 <= day3) <<  endl;
    // int a = 2;
    // cout << (day1 + 13) << endl;
    // cout << day2 << " > " << day3 << "? " << (day2 > day3) << endl;

    // cout << endl << "Comparisons" << endl;
    // cout << "Same day - test =" << (day1 == day4) << endl;
    // cout << "Different Day - test = " << (day1 == day2) << endl;
    // cout << "Same day - test != " << (day1 != day4) << endl;
    // cout << "Different Day - test != " << (day1 != day2) << endl;


    // cout << "Day " << day3.getDay() << endl;
    // cout << "Month " << monthNameToString(day3.getMonth()) << endl;
    // cout << "Year " << day3.getYear() << endl;
    return 0;
}
