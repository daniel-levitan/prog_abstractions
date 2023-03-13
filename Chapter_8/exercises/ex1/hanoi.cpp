/**
 * File: Hanoi.cpp
 * ---------------
 * This is the original implementation by the book. I've been working with a Stack 
 * implementation to makes things more practical on my side.
 * 
 * This program solves the Tower of Hanoi puzzle and count the number of moves.
 */

#include <iostream>
// #include "simpio.h"
using namespace std;

/* Function prototypes */

void moveTower(int n, char start, char finish, char tmp, int &count);
void moveSingleDisk(char start, char finish);

/* Main program */

int main() {
   int n = 8;
   int count = 0;
   moveTower(n, 'A', 'B', 'C', count);
   cout << "Moves: " << count << endl;
   return 0;
}

/**
 * Function: moveTower
 * Usage: moveTower(n, start, finish, tmp);
 * ----------------------------------------
 * Moves a tower of size n from the start spire to the finish
 * spire using the tmp spire as the temporary repository.
 */

void moveTower(int n, char start, char finish, char tmp, int &count) {
   count ++;
   if (n == 1) {
      moveSingleDisk(start, finish);
   } else {
      moveTower(n - 1, start, tmp, finish, count);
      moveSingleDisk(start, finish);
      moveTower(n - 1, tmp, finish, start, count);
   } 
}

/**
 * Function: moveSingleDisk
 * Usage: moveSingleDisk(start, finish);
 * -------------------------------------
 * Executes the transfer of a single disk from the start spire to the
 * finish spire.  In this implementation, the move is simply displayed
 * on the console; in a graphical implementation, the code would update
 * the graphics window to show the new arrangement.
 */

void moveSingleDisk(char start, char finish) {
   cout << start << " -> " << finish << endl;
}