/**
 * File: Hanoi.cpp
 * ---------------
 * This is the original implementation by the book. I've been working with a Stack 
 * implementation to makes things more practical on my side.
 * 
 * This program changes the solution to the Tower of Hanoi puzzle to work with 
 * the base case as 0.
 * 
 * For 4 discs we have 15 moves: 
 * A -> C, A -> B, C -> B, A -> C, B -> A, B -> C, A -> C, A -> B, C -> B, C -> A, 
 * B -> A, C -> B, A -> C, A -> B, C -> B.
 */


#include <iostream>
using namespace std;

/* Function prototypes */

void moveTower(int n, char start, char finish, char tmp, int &count);
void moveSingleDisk(char start, char finish);

/* Main program */

int main() {
   int n = 4;
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
   if (n == 0) {
      // moveSingleDisk(start, finish);
      return;
   } else {
      count ++;
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