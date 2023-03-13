/**
 * File: stringConv.cpp
 * -------------------------
 * Converting between string and 
 * 
 */

#include <iostream>
#include <string>
#include <sstream>
#include "../../libraries/error.h"

using namespace std;

enum alphabet {
    A = 10,
    B = 11,
    C = 12,
    D = 13,
    E = 14,
    F = 15,
    G = 16,
    H = 17,
    I = 18,
    J = 19,
    K = 20,
    L = 21,
    M = 22,
    N = 23,
    O = 24,
    P = 25,
    Q = 26,
    R = 27,
    S = 28,
    T = 29,
    U = 30,
    V = 31,
    W = 32,
    X = 33,
    Y = 34,
    Z = 35
};

string integerToString(int n, int base);

int main() {
    integerToString(123, 2);
    // cout << integerToString(123, 2) << endl;
    return 0;
}

string integerToString(int n, int base) {
    if (base < 2 or base > 36) 
        error("Base should be between 2 and 36");
    
    int number = n;
    int place = 0;

    while (number != 0) {
        int rest = number % base;
        
        cout << rest << endl;
        if (rest > 0) {

        }
        break;
    }


    string result = "return";
    return result;
    // ostringstream stream;
    // stream << n;
    // return stream.str();
}