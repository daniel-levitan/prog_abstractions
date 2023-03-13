/**
 * File: testDomino.cpp
 * --------------------
 * Converting types
 * 
 */

#include <iostream>
#include <string>
#include "console.h"
#include "domino.h"
#include "set.h"

using namespace std;

const int MAX = 6;

int main() {
//    Vector<Domino> set;
    Set<Domino> set;
    Domino tile;

    // Inserting
    for (int i = 1; i <= MAX; i++) {
        for (int j = 1; j <= MAX; j++) {
            tile = Domino(i, j);
            set.add(tile);
        }
    }

//    // Showing
//    for (Domino elem : set) {
//        cout << elem << endl;
//    }
    return 0;
}
