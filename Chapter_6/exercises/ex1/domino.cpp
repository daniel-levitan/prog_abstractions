/**
 * File: domino.cpp
 * -----------------
 * Implementing the domino class
 * 
 */

#include "domino.h"
//#include "../../../libraries/strlib.h"
//#include "../../../libraries/error.h"
#include "strlib.h"
#include "error.h"

using namespace std;


/*
 * Implementation notes: Constructors
 * ----------------------------------
 * The constructors initialize the instance variables left and right.  In the
 * second form of the constructor, the parameter names are leftc and rightc
 * to avoid the problem of shadowing the instance variables.
 */
Domino::Domino() {
    left = 0;
    right = 0;
}

Domino::Domino(int leftc, int rightc) {
    if ((leftc < 0) || (leftc > 6)) error("Left tile must be between 1 and 6");
    if ((rightc < 0) || (rightc > 6)) error("Right tile must be between 1 and 6");

    left = leftc;
    right = rightc;
}

/*
 * Implementation notes: Getters
 * -----------------------------
 * The getters return the value of the corresponding instance variable.
 * No setters are provided to ensure that Domino objects are immutable.
 */
int Domino::getLeftDots() {
   return left;
}
int Domino::getRightDots() {
   return right;
}

/*
 * Implementation notes: toString
 * ------------------------------
 * The implementation of toString uses the integerToString function
 * from the strlib.h interface.
 */
string Domino::toString() {
   return "[" + integerToString(left) + "|" + integerToString(right) + "]";
}

ostream & operator<<(ostream & os, Domino domino) {
    return os << domino.toString();
}
