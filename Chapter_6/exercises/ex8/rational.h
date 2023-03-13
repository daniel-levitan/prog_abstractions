/**
 * File: rational.h
 * Interface for the functions necessary to operate with rational
 * numbers
 */
 
#ifndef _rational_h
#define _rational_h

#include <string>

class Rational {

public:
	/**
	 * Constructor: Rational 
	 * Usage: Rational fraction(1, 1);
	 * 		  Rational fraction(r, s);
	 * -------------------------------
	 * Creater a Rational object. The default constructor sets the fraction to
	 * 1 / 1, and the second sets the fraction to r / s
	 */
	Rational();
	Rational(int n); 
	Rational(int n, int d); 


	/**
	 * Methods: sum, subtraction, multiplication, multiply
	 * Usage: Rational t = sum(r);
	 *        Rational t = subtraction(r);
	 *        Rational t = multiply(r);
	 *        Rational t = divide(r);
	 * --------------------------------------------------
	 * These methods implement the operations
	 */
	Rational sum(Rational s);
	Rational subtraction(Rational s);
	Rational multiply(Rational s);
	Rational divide(Rational s);

	/**
	 * Method: toString
	 * Usage:  string str = toString(r);
	 * -----------------------------------------
	 * This method displays the numerator and denominator as
	 * n / d
	 */
	std::string toString();

	/**
	 * Overloadings
	 */
	bool operator==(Rational s);
	bool operator!=(Rational s);
	
	Rational operator+(Rational s);
	Rational operator-(Rational s);
	Rational operator*(Rational s);
	Rational operator/(Rational s);
	Rational & operator+=(Rational s);
	Rational & operator-=(Rational s);
	Rational & operator*=(Rational s);
	Rational & operator/=(Rational s);
	bool operator>(Rational s);
	bool operator>=(Rational s);
	bool operator<(Rational s);
	bool operator<=(Rational s);
	Rational & operator++(); // prefix
	Rational operator++(int); // postfix
	Rational & operator--(); // prefix
	Rational operator--(int); // postfix
	

	// I will need a simplification function
private:
	int numerator;
	int denominator;
	friend int gcd(int a, int b);
	friend Rational simplifyFraction(Rational r);
	// int gcd(int a, int b);
	// Rational simplifyFraction(Rational r);
};

std::ostream & operator<<(std::ostream & os, Rational r);

// Auxiliary functions
int gcd(int x, int y);
int lcm(int x, int y);
Rational simplifyFraction(Rational r);


#endif
