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
    Date d1 = Date(25, FEBRUARY, 1999);
    Date d2 = Date(7, JUNE, 2003);   
    cout << "d1     " << d1 << endl;
    cout << "d2     " << d2 << endl;
    cout << "d2-d1  " << d2 - d1 << endl;
    // d2 - d1;
    cout << endl;

    Date d3 = Date(26, FEBRUARY, 2000);
    cout << "d1     " << d1 << endl;
    cout << "d3     " << d3 << endl;
    cout << "d3-d1  " << d3 - d1 << endl;
    // d3 - d1;
    cout << endl;
    

    Date d4 = Date(26, FEBRUARY, 2004);
    cout << "d2     " << d2 << endl;
    cout << "d4     " << d4 << endl;
    cout << "d4-d2  " << d4 - d2 << endl;
    // d4 - d2;
    cout << endl;    

    cout << "d1     " << d1 << endl;
    cout << "d4     " << d4 << endl;
    cout << "d4-d1  " << d4 - d1 << endl;
    // d4 - d2;
    cout << endl;    
    

    return 0;
}