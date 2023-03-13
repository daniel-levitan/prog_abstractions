/**
 * File: rational.cpp
 * Implementation of the rational interface
 * 
 */

#include <iostream>
#include <string>
#include "rational.h"
#include "../../../libraries/error.h"
#include "../../../libraries/strlib.h"
#include <algorithm>
#include <cstdlib>

/**
 * The two functions below gcd and simplifyFraction are declared as free here
 * but as friend within the class in rational.h
 * int gcd(int a, int b) {
 * 	  if (a == 0)
 * 	     return b;
 *    return gcd(b % a, a);
 * }
 */

// Greatest common divisor
// This is defined in the book
int gcd(int x, int y) {
	int r = x % y;
	while (r != 0) {
		x = y;
		y = r;
		r = x % y;
	}
	return y;
}

int lcm(int x, int y) {
	return (x * y) / gcd(x, y);
}

Rational simplifyFraction(Rational r) {
	int max = gcd(r.numerator, r.denominator);	
	return Rational(r.numerator / max, r.denominator / max );
}

Rational::Rational() {
	numerator = 0;
	denominator = 1;
}

Rational::Rational(int n) {
	numerator = n;
	denominator = 1;	
}

Rational::Rational(int n, int d) {
	if (d == 0) error("Error: Rational by zero");
	if (n == 0) {
		numerator = 0;
		denominator = 1;
	} else {
		int g = gcd(abs(n), abs(d));
		numerator = n / g;
		denominator = abs(d) / g;
		if (d < 0) numerator = -numerator;
	}
}

/**
 * a   c   a * d + b * c
 * - + - = -------------
 * b   d       b * d
 * 
 */
Rational Rational::sum(Rational s) {
	return simplifyFraction(Rational(numerator * s.denominator + denominator * s.numerator, 
									 denominator * s.denominator));
}

/**
 * a   c   a * d - b * c
 * - - - = -------------
 * b   d       b * d
 * 
 */
Rational Rational::subtraction(Rational s) {
	return simplifyFraction(Rational(numerator * s.denominator - denominator * s.numerator, 
									 denominator * s.denominator));
}

/**
 * a   c   a * c
 * - * - = -----
 * b   d   b * d
 * 
 */
Rational Rational::multiply(Rational s) {
	return simplifyFraction(Rational(numerator * s.numerator, 
									 denominator * s.denominator));
}

/**
 * a   c   a * d
 * - / - = -----
 * b   d   b * c
 * 
 */
Rational Rational::divide(Rational s) {
	return simplifyFraction(Rational(numerator * s.denominator, 
									 denominator * s.numerator));
}

std::string Rational::toString() {
	return integerToString(numerator) + "/" +
	       integerToString(denominator);
}

bool Rational::operator==(Rational s) {
	return numerator == s.numerator && denominator == s.denominator;
}

bool Rational::operator!=(Rational s) {
	return !operator==(s);
}

bool Rational::operator>(Rational s) {
	int lcmFactor = lcm(denominator, s.denominator);

	return numerator * lcmFactor / denominator > 
		   s.numerator * lcmFactor / s.denominator;
}

bool Rational::operator>=(Rational s) {
	if (operator==(s)) return true;
	return operator>(s);
}

bool Rational::operator<(Rational s) {
	int lcmFactor = lcm(denominator, s.denominator);

	return numerator * lcmFactor / denominator < 
		   s.numerator * lcmFactor / s.denominator;
}

bool Rational::operator<=(Rational s) {
	if (operator==(s)) return true;
	return operator<(s);
}

Rational Rational::operator+(Rational s) {
	return sum(s);
}

Rational & Rational::operator+=(Rational s) {
	Rational result = operator+(s);
	numerator = result.numerator;
	denominator = result.denominator;
	return *this;
}

Rational Rational::operator-(Rational s) {
	return subtraction(s);
}

Rational & Rational::operator-=(Rational s) {
	Rational result = operator-(s);
	numerator = result.numerator;
	denominator = result.denominator;
	return *this;
}

Rational Rational::operator*(Rational s) {
	return multiply(s);
}

Rational & Rational::operator*=(Rational s) {
	Rational result = operator*(s);
	numerator = result.numerator;
	denominator = result.denominator;
	return *this;
}

Rational Rational::operator/(Rational s) {
	return divide(s);
}

Rational & Rational::operator/=(Rational s) {
	Rational result = operator/(s);
	numerator = result.numerator;
	denominator = result.denominator;
	return *this;
}

// prefix
Rational & Rational::operator++() {
	operator+=(Rational(1));
	return *this;
}

// postfix
Rational Rational::operator++(int) {
	Rational result = Rational(numerator, denominator);
	operator+=(Rational(1));
	return result;
}

// prefix
Rational & Rational::operator--() {
	operator-=(Rational(1));
	return *this;
}

// postfix
Rational Rational::operator--(int) {
	Rational result = Rational(numerator, denominator);
	operator-=(Rational(1));
	return result;
}
std::ostream & operator<<(std::ostream & os, Rational r) {
	return os << r.toString();
}

