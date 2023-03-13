/**
 * File: intArray.cpp
 * ------------------
 * This file implements the interface IntArray.
 */

#include <iostream>
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

int IntArray::size() const {
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

void IntArray::print() const {
    for (int i = 0; i < capacity; i++)
        std::cout << array[i] << " ";
    std::cout << std::endl;
}


int & IntArray::operator[](int k) {
    if ((k >= 0) and (k < capacity)) {
        return array[k];
    }
    return array[count - 1];
}

void IntArray::deepCopy(const IntArray & src) {
    array = new int[src.count]; // Pq ele consegue acessar count?
    for (int i = 0; i < src.count; i++)
        array[i] = src.array[i];
    count = src.count;
    capacity = src.capacity;
}

IntArray::IntArray(const IntArray & src) {
    deepCopy(src);
}


