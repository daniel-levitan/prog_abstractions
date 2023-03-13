/**
 * File: card.h
 * --------------
 * Interface for the card class
 *
 */

#ifndef _card_h
#define _card_h

#include <iostream>
#include <string>

enum Suit { CLUBS, DIAMONDS, HEARTS, SPADES };

const int ACE = 1;
const int JACK = 11;
const int QUEEN = 12;
const int KING = 13;

class Card {
public:
    /**
     * Constructor: Card()
     * Usage:       Domino Card();
     *              Domino domino(rankc, suitc);
     *              Domino domino(rank_suit);
     * ----------------------------------------
     * Create a card. The default constructor does not set the rank and suit values;
     * the second form sets the values to rankc and suitc. The third constructor
     * gets the small representations "10S" or "JD".
     */

    Card();
    Card(int rankc, Suit suitc);
    Card(std::string shortRep);

    /*
    * Methods: getRank, getSuit
    * Usage: int rank  = card.getRank();
    *        Suit suit = card.getSuit();
    * -------------------------------------
    * These methods return rank and suit of the card.
    */

    int getRank();
    Suit getSuit();

    /**
    * Method: toString
    * Usage: string str = card.toString();
    * ------------------------------------
    * Returns a string representation of the card in the form "Rank Suit".
    */
    std::string toString();

private:
    int rank;
    Suit suit;
};

std::ostream & operator<<(std::ostream & os, Card card);

std::string suitToString(Suit suit);
Suit stringToSuit(std::string stringSuit);
std::string rankToString(int rank);

Suit operator++(Suit & suit);
Suit operator++(Suit & suit, int);


#endif
