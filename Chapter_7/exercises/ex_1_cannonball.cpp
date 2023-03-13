/**
 * File: ex_1_cannonball.cpp
 * -------------------------
 * Solving the cannonball exercise
 * 1-4-9-16-25
 * 1-2-3-4-5
 */

#include <iostream>
#include <string>

using namespace std;


int getBalls(int h);

int main() {
    cout << getBalls(1) << endl;
    cout << getBalls(2) << endl;
    cout << getBalls(3) << endl;
    cout << getBalls(4) << endl;
    return 0;
}

int getBalls(int h) {
    if ((h == 1) || (h == 0))
        return 1;
    else
        return h * h + getBalls(h - 1);
}
