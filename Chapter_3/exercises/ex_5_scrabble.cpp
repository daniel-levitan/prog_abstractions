/**
 * File: ex_5_scrabble.cpp
 * -----------------------
 * Write a program that reads in words and prints out their score in Scrabble, 
 * not counting any of the other bonuses that occur in the game.
 */

#include <iostream>
#include <string>

using namespace std;

int getPoints(char ch);
int calculateValue(string str);

int main() {
    
    // cout << "A: " << getPoints('A') << endl;
    // cout << "U: " << getPoints('U') << endl;
    // cout << "G: " << getPoints('G') << endl;
    // cout << "C: " << getPoints('C') << endl;
    // cout << "W: " << getPoints('W') << endl;
    // cout << "K: " << getPoints('K') << endl;
    // cout << "J: " << getPoints('J') << endl;
    // cout << "Z: " << getPoints('Z') << endl;
    cout << "Value: " << calculateValue("FARM") << endl;
    return 0;
}




int getPoints(char ch) {
    switch (ch) {
        case 'A': case 'E': case 'I': case 'L': case 'N':
        case 'O': case 'R': case 'S': case 'T': case 'U':
            return 1;
        case 'D': case 'G':
            return 2;
        case 'B': case 'C': case 'M': case 'P':
            return 3;
        case 'F': case 'H': case 'V': case 'W': case 'Y':
            return 4;
        case 'K':
            return 5;
        case 'J': case 'X':
            return 8;
        case 'Q': case 'Z':
            return 10;
        default:
            return 0;
    }
}

int calculateValue(string str) {
    int points = 0;
    for (int i = 0; i < str.length(); i++)
        points += getPoints(str[i]); 
    return points;
}