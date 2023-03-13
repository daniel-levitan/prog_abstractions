/**
 * File: card.cpp
 * -----------------
 * Implementing the card class
 *
 */

#include "card.h"
#include "strlib.h"
//#include "error.h"

using namespace std;

/*
 * Implementation notes: Constructors
 * ----------------------------------
 * The constructors initialize the instance variables rank and suit.  In the
 * second form of the constructor, the parameter names are rankc and suitc
 * to avoid the problem of shadowing the instance variables.
 */
Card::Card() {
}


Card::Card(int rankc, Suit suitc) {
    rank = rankc;
    suit = suitc;
}

Card::Card(std::string shortRep) {

    std::string suitStr = shortRep.substr(shortRep.length() - 1);
    suit = stringToSuit(suitStr);
    rank = stringToInteger(shortRep.substr(0, shortRep.length() - 1));
}

/**
 * Implementation notes: Getters
 * -----------------------------
 * The getters return the value of the corresponding instance variable.
 * No setters are provided to ensure that card objects are immutable.
 */
int Card::getRank() {
   return rank;
}
Suit Card::getSuit() {
   return suit;
}

/*
 * Implementation notes: toString
 * ------------------------------
 * The implementation of toString uses the integerToString function
 * from the strlib.h interface.
 */

string Card::toString() {
   return rankToString(rank) + suitToString(suit);
}

ostream & operator<<(ostream & os, Card card) {
    return os << card.toString();
}


std::string rankToString(int rank) {
    switch (rank) {
        case 1:
            return "A";
        case 11:
            return "J";
        case 12:
            return "Q";
        case 13:
            return "K";
        default:
            return integerToString(rank);
    }
}

std::string suitToString(Suit suit) {
    switch (suit) {
        case CLUBS:
            return "C";
        case DIAMONDS:
            return "D";
        case HEARTS:
            return "H";
        case SPADES:
            return "S";
        default:
            return "No Suit"; // error
    }
}

Suit stringToSuit(std::string stringSuit) {
    if (stringSuit == "C")
        return CLUBS;

    if (stringSuit == "D")
        return DIAMONDS;

    if (stringSuit == "H")
        return HEARTS;

    return SPADES;
}

// ++suit
Suit operator++(Suit & suit) {
    suit = Suit(suit + 1);
    return suit;
}

// suit++
Suit operator++(Suit & suit, int) {
    Suit old = suit;
    suit = Suit(suit + 1);
    return old;
}
