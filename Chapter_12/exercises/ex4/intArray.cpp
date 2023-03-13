/**
 * File: intArray.cpp
 * ------------------
 * This file implements the interface IntArray.
 */


#include "intArray.h"
#include "../../../libraries/error.h"


IntArray::IntArray(int n) {
    // capacity = INITIAL_CAPACITY;
    capacity = n;
    array = new int[capacity];
    count = 0;
    for (int i = 0; i < capacity; i++)
        array[i] = 0;
}

IntArray::~IntArray() {
    delete[] array;
}

int IntArray::size() {
    return count;
}

int IntArray::get(int k) {
    if ((k >= 0) and (k < capacity)) 
        return array[k];
    error("Index out of bounds");
    return array[count - 1];
}

void IntArray::put(int k, int value) {
    if ((k >= 0) and (k < capacity)){
        array[k] = value;
        count++;
    } else {
        error("Index out of bounds");
    }
}

