/*
 * File: ex_1_weekdays.cpp
 * -----------------------
 * This program solves exercise #1
 * 
 * Define an enumeration type weekdayT whose elements are the days of the week. 
 *
 * Write functions NextDay and PreviousDay that take a value of type weekdayT 
 * and return the day of the week that comes after or before the specified day, 
 * respectively.
 * 
 * write a function IncrementDay(startDay, delta) that returns the day of the 
 * week that comes delta days after start Day.
 *
 */

#include <iostream>
// #include <iomanip>

using namespace std;

enum weekdayT { Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday};
// 0, 1, 2, 3, 4, 5, 6

weekdayT nextDay(weekdayT day);
weekdayT previousDay(weekdayT day);
string weekdayName(weekdayT day);
weekdayT incrementDay(weekdayT startDay, int delta);

int main() {
	weekdayT day = Sunday;

	// for (int i = 0; i < 8; i++) {
 //        cout << weekdayName(day) << endl;
        
 //        day = nextDay(day);
 //        // day = previousDay(day);

 //    }

	day = incrementDay(day, -3);
	cout << weekdayName(day) << endl;
	return 0;
}

weekdayT nextDay(weekdayT day) {
	return weekdayT((day + 1) % 7);
}

weekdayT previousDay(weekdayT day) {
	return weekdayT((7 + day - 1) % 7);
}

weekdayT incrementDay(weekdayT startDay, int delta) {
	weekdayT finalDay = startDay;

	if (delta > 0) {
		for (int i = 0; i < delta; i++) finalDay = nextDay(finalDay);
	}
	else {
		for (int i = 0; i < -delta; i++) finalDay = previousDay(finalDay);	
	}
	return finalDay;
}

string weekdayName(weekdayT day) {
    switch (day) {
        case Sunday:    return "Sunday";
        case Monday:    return "Monday";
        case Tuesday:   return "Tuesday";
        case Wednesday: return "Wednesday";
        case Thursday:  return "Thursday";
        case Friday:    return "Friday";
        case Saturday:  return "Saturday";
        default:        return "Error";
    } 
}