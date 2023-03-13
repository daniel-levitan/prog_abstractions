/**
 * File: domino.h
 * --------------
 * Interface for a domino class
 * 
 */

#ifndef _domino_h
#define _domino_h

#include <iostream>
#include <string>


class Domino {
public:
    /**
     * Constructor: Domino()
     * Usage:       Domino domino();
     *              Domino domino(leftc, rightc);
     * ----------------------------------------
     * Create a domino tile. The default constructor sets the left and right values
     * to 0; the second form sets the values to leftc and rightc.
     */

    Domino();
    Domino(int leftc, int rightc);
    

    /*
    * Methods: getLeft, getRight
    * Usage: int left  = domino.getLeftDots();
    *        int right = domino.getRightDots();
    * -------------------------------------
    * These methods return the x and y coordinates of the point.
    */

    int getLeftDots();
    int getRightDots();

    /**
    * Method: toString
    * Usage: string str = domino.toString();
    * ------------------------------------
    * Returns a string representation of the domino tile in the form "[x|y]".
    */
    std::string toString();

private:
    int left;
    int right;        
};

std::ostream & operator<<(std::ostream & os, Domino domino);

#endif