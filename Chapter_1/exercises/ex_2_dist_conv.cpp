/*
 * File: ex_2_dist_conv.cpp
 * ------------------------
 * This program solves exercise #2.
 * Write a program that converts a distance in meters to the corresponding English
 * distance in feet and inches. The conversion factors you need are
 *
 * 1 inch = 0.0254 meters 
 * 1 foot = 12 inches
 *
 */

#include <iostream>
#include "../../libraries/simpio.h"

using namespace std;

const double INCH_TO_METERS = 0.0254;
const double FOOT_TO_METERS = 12 * INCH_TO_METERS;

int main(){

    string prompt = "Enter the distance in meters: ";
    double distInM = getReal(prompt);
    
    double distInI = distInM / INCH_TO_METERS;
    double distInF = distInM / FOOT_TO_METERS;
    cout << "The distance in inches is " << distInI << " inches" << endl;
    cout << "The distance in feet is   " << distInF << " feet" << endl;
    return 0;
}

