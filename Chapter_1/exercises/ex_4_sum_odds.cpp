/*
 * File: ex_4_sum_odds.cpp
 * ------------------------
 * This program solves exercise #4.
 * The program reads in a positive integer N and then calculates and 
 * displays the sum of the first N odd integers. 
 * 
 * For example, if N is 4, your program should display the value 16, 
 * which is 1 + 3 + 5 + 7.
 * 
 */

#include <iostream>
#include "../../libraries/simpio.h"

using namespace std;

int main(){

    string prompt = "Enter a integer number: ";
    int n = getInteger(prompt);
    
    int i = 0;
    int sum = 0;
    int count = 0;
    

    while (count != n) {
    	if ((i % 2) != 0) {
    		sum += i;
    		count++;
    	}
    	i++;
    }

    cout << "The sum of the odds up to " << n <<  " is " << sum << endl;
    return 0;
}

