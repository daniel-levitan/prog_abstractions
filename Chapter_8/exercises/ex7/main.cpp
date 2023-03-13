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
#include "vector.h"

using namespace std;

//const int MAX = 6;


void printVector (Vector<Card> &vec);
int countFifteens(Vector<Card> & cards);

int main() {

//    Vector<Card> cardSet;

    // === Gerar 1 set de cartas ===
//    for (Suit suit = CLUBS; suit <= SPADES; suit++) {
//        for (int rank = ACE; rank <= KING; rank++) {
//            cardSet.add(Card(rank, suit));
//        }
//        cout << endl;
//    }
//    printVector(cardSet);

    // === Escolher 5 aleatoriamente ===
    Vector<Card> hand;
    hand.add(Card("AD"));
    hand.add(Card("10S"));
    hand.add(Card("4H"));
    hand.add(Card("5C"));
    hand.add(Card("9C"));
    printVector(hand);

    // Contar as maneiras em que elas podem somar 15


    return 0;
}

int countFifteens(Vector<Card> & cards) {

    return 0;
}

void printVector (Vector<Card> &vec) {
    cout << "[";
    for (int i = 0; i < vec.size(); i++) {
        if (i > 0) cout << ", ";
        cout << vec[i];
    }
    cout << "]" << endl;
}
