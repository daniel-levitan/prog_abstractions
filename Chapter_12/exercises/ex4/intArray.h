/**
 * File: intArray.h
 * ------------------
 * This interface defines the IntArray class, which implements
 * an array of integers.
 */

#ifndef _intArray_h
#define _intArray_h

#include <iostream>
#include "../../../libraries/error.h"

/**
 * Class: IntArray
 * ---------------
 * This Class represents an array of integers.
 */
class IntArray {

public:

    /**
     * Constructor: IntArray
     * Usage: IntArray arr = IntArray(n);
     * ----------------------------------
     * Creates an array of int will all elements set to 0.
     */
    IntArray(int n);


    /**
     * Destructor: ~IntArray
     * Usage: ~IntArray();
     * ----------------------------------
     * Frees the memory of the array.
     */
    ~IntArray();

    /**
     * Method: size
     * Usage: int sz = size();
     * ----------------------------------
     * Returns the size of the array.
     */
    int size();

    /**
     * Method: get
     * Usage: int element = get(k);
     * ----------------------------------
     * Returns the element at index k.
     */
    int get(int k);

    /**
     * Method: put
     * Usage: put(k, value);
     * ----------------------------------
     * Insert value at index k.
     */
    void put(int k, int value);

private:

    // static const int INITIAL_CAPACITY = 10;

    int *array;
    int count;
    int capacity;

    void expandCapacity();
};




#endif