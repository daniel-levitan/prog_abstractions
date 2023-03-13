/*
 * File: ex_2_cilinder.cpp
 * -----------------------
 * This program solves exercise #2.
 * 
 * Write a program that computes the surface area and volume of a cylinder, 
 * given the height (h) and radius of the base (r).
 *
 * A = 2 * π * h * r
 * V = π * h * r^2
 * 
 * In this exercise, design your main program so that it consists of three function 
 * calls: 
 * 1. one to read the input data 
 * 2. one to compute the results 
 * 3. one to display the answers 
 *
 * When appropriate, use call by reference to communicate data between the functions and * the main program.
 */
#include <iostream>
#include "../../libraries/simpio.h"

using namespace std;

const double PI  =3.141592653589793238463;

void getInput(double *height, double *radius);
void compute(double *height, double *radius, double *area, double *volume);
void display(double *area, double *volume);

int main() {
	
	double *height = new double;
	double *radius = new double;
	double *area = new double;
	double *volume = new double;
	
	getInput(height, radius);
	compute(height, radius, area, volume);
	display(area, volume);	

	delete height;
	delete radius;
	delete area;
	delete volume;
	return 0;
}


void getInput(double *height, double *radius) {	
	string prompt_height = "Enter height: ";
	*height = getReal(prompt_height);

	string prompt_radius = "Enter radius: ";
	*radius = getReal(prompt_radius);	
}

void compute(double *height, double *radius, double *area, double *volume) {
	*area = 2 * PI * (*height) * (*radius);
	*volume = PI * (*height) * (*radius) * (*radius);
}


void display(double *area, double *volume) {	
	cout << endl;
	cout << "Area   : " << (*area) << endl;
	cout << "Volume : " << (*volume) << endl;
}

