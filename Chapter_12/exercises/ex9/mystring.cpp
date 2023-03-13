/**
 * File: mystring.cpp
 * ------------------
 * This file implements the interface MyString.
 */

/**
 * As an improvement over the string class in the C++ libraries, your 
 * implementation of the bracket operator should call error if the index is 
 * outside the bounds of the string.
 * 
 * A redefinition of the relational operators ==, !=, <, <=, >, and >= that 
 * compare strings lexicographically.
 * 
 */


#include <iostream>
#include "mystring.h"

MyString::MyString() {
	myLength = INITIAL_CAPACITY;
	myStr = new char[myLength]; 
}

MyString::MyString(std::string str) {
	myLength = str.length();
	myStr = new char[myLength];
	
	for (int i = 0; i < myLength; i++)
		myStr[i] = str[i];
}

MyString::~MyString() {
	delete[] myStr;
}

std::string MyString::toString() {
	std::string result = "";
	if (myLength > 0) {
		for (int i = 0; i < myLength; i++) 
			result += myStr[i];
	}
	return result;
}

int MyString::length() {
	return myLength;
}

MyString MyString::substr(int start) {
	MyString result = MyString();
	result.myLength = myLength - start;
	if ((start >= 0) and (start < myLength)) {
		for (int i = 0; i < myLength - start; i++) 
			result.myStr[i] = myStr[start + i];
	}
	return result;
}

MyString MyString::substr(int start, int n) {
	MyString result = MyString();
	result.myLength = n - start + 1;
	if ((start >= 0) and (start < myLength) and (n < myLength)) {
		for (int i = 0; i < n - start + 1; i++) 
			result.myStr[i] = myStr[start + i];
	}
	return result;
}

char & MyString::operator[](int k) {
	if ((k >= 0) and (k < myLength))
		return myStr[k];
	return myStr[myLength - 1];
}

MyString & MyString::operator+=(char c) {
	myLength += 1;
	char *temp = new char[myLength - 1];
	
	for (int i = 0; i < myLength - 1; i++) 
		temp[i] = myStr[i];

	myStr = new char[myLength];
	for (int i = 0; i < myLength - 1; i++) 
		myStr[i] = temp[i];
	
	myStr[myLength - 1] = c;
	delete[] temp; 

	return *this;
}

MyString MyString::operator+(MyString str) {
	return MyString(this->toString() + str.toString());
}

MyString::MyString(const MyString & src) {
	deepCopy(src);
}

MyString & MyString::operator=(const MyString & src) {
	if (this != &src) {
		delete [] myStr;
		deepCopy(src);
	}
	return *this;
}

void MyString::deepCopy(const MyString & src) {
	myStr = new char[src.myLength];
	for (int i = 0; i < src.myLength; i++)
		myStr[i] = src.myStr[i];
	myLength = src.myLength;
}

std::ostream & operator<<(std::ostream & os, MyString &str) {
	return os << str.toString();
}



