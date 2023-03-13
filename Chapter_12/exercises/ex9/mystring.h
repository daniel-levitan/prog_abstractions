/**
 * File: mystring.h
 * ----------------
 * This inferface defines the MyString class which implements a string.
 */

/**  
 * As an improvement over the string class in the C++ libraries, your 
 * implementation of the bracket operator should call error if the index is 
 * outside the bounds of the string.
 * 
 * A redefinition of the relational operators ==, !=, <, <=, >, and >= that 
 * compare strings lexicographically.
 */


#ifndef _mystring_h
#define _mystring_h


#include <string>

class MyString {
public:
	/** 
	 * Constructor: MyString
	 * Usage      : MyString str;
	 *              MyString str = "abc";
	 * ----------------------------------
	 * Creates a MyString object. In the first case empty, in the second case
	 * with the char array it is provided with.
	 */
	MyString();
	MyString(std::string str);
	MyString(const MyString & src);

	/**
	 * Destructor: ~MyString
	 * ---------------------
	 * Frees the memory used by the object. 
	 */
	~MyString();

	/**
	 * Method: toString()
	 * Usage: std::string newStr = str.toString();
	 * -------------------------------------------
	 * Converts a MyString to a C++ string
	 */
	std::string toString();

	/**
	 * Method: length();
	 * Usage: int a = str.length();
	 * ----------------------------
	 * Returns the length of the string.
	 */
	int length();
	
	/**
	 * Method: substr(int start)
	 *         substr(int start, int n)
	 * Usage: MyString newStr = original.substr(3);
	 *        MyString newStr = original.substr(3, 5);
	 * ------------------------------------------------
	 * Those method return a substring of the current string object. 
	 * As in the library version of the string class, the substring should
 	 * begin at the index position start and continue for n characters or through 
 	 * the end of the string, whichever comes first. The parameter n should be 
 	 * optional; if it is missing, the substring should always extend through the
 	 * end of the original string.
	 */
	MyString substr(int start); 
	
	MyString substr(int start, int n); 

	/**
	 * Overloadings
	 */
	char & operator[](int k);
	
	MyString operator+(MyString str);

	MyString & operator+=(char c);
	MyString & operator=(const MyString & src);


private:
	static const int INITIAL_CAPACITY = 10;

	char *myStr;
	int myLength;

	void deepCopy(const MyString & src);

};

std::ostream & operator<<(std::ostream & os, MyString &str);




#endif