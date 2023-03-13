/**
 * File: ex_14_pi_circle.cpp
 * -----------------------
 * This program solves exercise #14 of the new book.
 */

#include <iostream>
#include "../../libraries/random.h"

using namespace std;

const int SIM_NUM = 50000;

int main() {
    
    double in = 0;    
    
    for (int i = 0; i < SIM_NUM; i++){
        double x = randomReal(-1, 1);
        double y = randomReal(-1, 1);

        if ((x * x + y * y) < 1) in++;
    }

    cout << "Pi is: " << 4 * (in / SIM_NUM)  << endl;
    return 0;
}