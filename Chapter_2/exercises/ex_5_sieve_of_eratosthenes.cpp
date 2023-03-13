/*
 * File: ex_5_sieve_of_eratosthenes.cpp
 * ------------------------------------
 * This program solves exercise #5.
 * 
 */

#include <iostream>

using namespace std;

const int N = 1000;
const int SIZE = N - 1;

void generateArray(int array[]);
void printArray(int array[]);
void getPrimes(int array[], int result[]);
void copyArray(int src[], int dest[]);
void printNonZero(int array[]);

int main() {
    
    int array[SIZE];
    int result[SIZE];

    // cout << "Size of array " << sizeof(array) / sizeof(int) << endl;
    
    generateArray(array);
    // printArray(array);
    getPrimes(array, result);
    printNonZero(result);

    return 0;
}


void getPrimes(int array[], int result[]) {
    copyArray(array, result);
    int pivot;

    for (int i = 0; i < SIZE; i++) {
        if (result[i] != 0) {
            pivot = result[i];
            for (int j = i + 1; j < SIZE; j++) {
                if ((result[j] % pivot) == 0) {
                    result[j] = 0;
                } 
            }
        }
    }
}

void generateArray(int array[]) {
    int i, j; // for initializing 2 variable in the for loop
    for (i = 0, j = 2; i < SIZE; i++, j++) 
        array[i] = j;
}

void printArray(int array[]) {
    for (int i = 0; i < SIZE; i++)
        cout << array[i] << " ";
    cout << endl;
}

void copyArray(int src[], int dest[]) {
    for (int i = 0; i < SIZE; i++) {
        dest[i] = src[i];
    }
}

void printNonZero(int array[]) {
     for (int i = 0; i < SIZE; i++) {
        if (array[i] != 0) 
            cout << array[i] << " ";    
     }  
    cout << endl;
}
