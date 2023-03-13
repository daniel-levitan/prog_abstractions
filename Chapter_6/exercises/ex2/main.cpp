/**
 * File: main.cpp
 * --------------------
 * Testing cards
 *
 */

#include <iostream>
#include <string>
#include "console.h"
#include "card.h"

using namespace std;

//const int MAX = 6;

int main() {
    Card card = Card("10D");
    cout << card << endl;


//    Card card;
//    Card card2 = Card(2, CLUBS);
//    cout << card2 << endl;

//    Card card1 = Card(1, HEARTS);
//    cout << card1 << endl;

//    Card card3 = Card(ACE, HEARTS);
//    cout << card3 << endl;

//    Suit mySuit = SPADES;
//    cout << suitToString(mySuit) << endl;
//    mySuit++;
//    mySuit = Suit();
//    cout << suitToString(mySuit) << endl;

//    for (Suit suit = CLUBS; suit <= SPADES; suit++) {
//        for (int rank = ACE; rank <= KING; rank++) {
//            cout << " " << Card(rank, suit);
//        }
//        cout << endl;
//    }

    return 0;
}
