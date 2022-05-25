//
//  Range.h
//  HW6
//
//  Created by Lance Aquino on 2/12/22.
//

#include <string>
#include "Card.h"
#include <vector>

/**
This function creates a new std::vector<Card>, or deck, that contains all 52 possible Cards
 
 @return a vector containing all 52 possible cards in a standard complete deck of cards
 */
std::vector<Card>create_deck();

/**
This function is passed a Card as an input and returns the card’s value as an int;
 
 @param inputted_card a card whose value is read, based on the suit, face, and certain conditions
 
 @return the int value of the inputted card, which depends on the face and suit of the card
 */
int cardValue(const Card& inputted_card);

/**
Function that accepts an std::vector<Card> representing the deck of undealt cards, chooses a card at random and removes it from the deck, and returns that selected Card;
 
 @param deck  a reference to a vector containing Card objects. Changes based on what cards have been drawn from the deck during a round
 
 @return a Card class, that was randomly chosen and subsequently removed from a given vector of Card objects, or a deck
 */
Card dealCard( std::vector<Card> &deck );

/**
Function that accepts an std::vector<Card> representing the player’s hand and an int for the total value of cards in their hand, and displays the value of  their hand, as well as cards in said hand, to the console;
 
 @param hand_val an int representing the total value of the user's current hand
 @param hand a vector contaning Card objects that have been drawn by the user over the course of a round
*/
void showHand (const int hand_val, const std::vector<Card>& hand);

/**
Function that accepts two arguments, an int representing the max possible hand value allowed and an int representing the user’s hand value, returning true only if the user’s hand value has exceeded the maximum possible hand value allowed;
 
 @param hand_up_bound an int representing the maximum possible value of a hand
 @param current_hand_val an int representing the total value of the user's hand
 
 @return a boolean that is true if the upper bound has been exceeded, false otherwise
*/
bool exceeds(int hand_up_bound, int current_hand_val);

/**
inRange, which accepts three arguments, an int representing the target lower bound for a hand value; an int representing the maximum possible hand value allowed; and an int representing the user’s hand value, returning true only if the user’s hand value is within the target range. Inclusive of both upper and lower bounds
 
 @param hand_low_bound the lower bound of the target range of the user's hand
 @param hand_up_bound the upper bound of the target range of the user's hand
 @param current_hand_val the sum of the values of all cards in the user's current hand
 
 @return a boolean that is true if the user's hand's value is within the range encapsulated by the upper and lower bound  (inclusive)
*/

bool inRange(int hand_low_bound, int hand_up_bound, int current_hand_val);


