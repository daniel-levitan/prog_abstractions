/*
 * File: ex_1_temp_conv.cpp
 * ------------------------
 * This program solves exercise #1.
 * Write a program that reads in a temperature in degrees Celsius 
 * and displays the corresponding temperature in degrees Fahrenheit. 
 *
 * F = (9 / 5) * C + 32
 *
 */

#include <iostream>
#include "../../libraries/simpio.h"

using namespace std;

int main(){
    string prompt = "Enter a temperature in degrees Celsius: ";
    double tempInC = getReal(prompt);
    double tempInF = (9.0 / 5.0) * tempInC + 32.0;
    cout << "Temperature in Fahrenheits is " << tempInF << " F" << endl;
    return 0;
}

