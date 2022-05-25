//
//  Range.cpp
//  HW6
//
//  Created by Lance Aquino on 2/12/22.
//

#include <iostream>
#include "Card.h"
#include "Range.h"
#include <vector>
#include <string>

std::vector<Card>create_deck (){ // generates a new full deck of 52 cards
    std::vector<Card> full_deck;
    std::vector<std::string> all_faces = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
    std::vector<std::string> all_suits = {"Hearts","Spades","Diamonds","Clubs"};
    for (std::string current_suit: all_suits){ //iterates through the possible suits
        for (std::string current_face : all_faces ){ // iterates through the possible faces
            Card current_card = Card(current_suit, current_face); // creates a Card object using the current face and suit
            full_deck.push_back(current_card); // populates an std::vector<Card> with the new Card object
        }
    }
    return full_deck;
}

int cardValue(const Card & inputted_card){
    int card_val = 0;
    int ascii_zero = '0'; // the ascii value of 0, in order to convert the char numbers into the int numbers that they represent, during the first if statement
    std::string card_string = inputted_card.card_as_string(); // converts a Card object into a string
    char card_face = card_string[0]; // gets the face of the card from the first character in the card_string, as a char class
    if (card_face == '2' || card_face == '3' || card_face == '4' || card_face == '5' || card_face == '6' || card_face == '7' || card_face == '8' || card_face == '9' || card_face == '1' ){ // checks if Card's face is a number, which means that its value will be the same value as the face
        if (card_face != '1'){ // The number 1 can only be the first char of the string if the face is 10, since there is no card with the face "1" whose value is 1. Any other numbered face will have the same value as the char stored in card_face.
            card_val = card_face - ascii_zero; // converts the char into the number it represents, by substracting the ascii value of 0 from it
        }
        else{ // the only other numbered card face is 10
            card_val = 10;
        }
    }
    else if (card_face == 'J' || card_face == 'Q' || card_face == 'K'){ // all cards with a face of J,Q, or K have a value of 11
        card_val = 11;
    }
    else { // The only type of cards left are A's, whose value depends on suit
        size_t first_bracket_pos = 1; // the first bracket in any Ace card is located at an index of 1
        std::string card_suit = card_string.substr(first_bracket_pos); // checks the card suit of an ace, by reading a substring starting from the first bracket
        if (card_suit == "[Spades]"){ // only an A[Spades] yields a value of 12
            card_val = 12;
        }
        else{ //any other possible card (i.e. any other A card) has a value of 1
            card_val =1;
        }
    }
    return card_val;
}


Card dealCard(std::vector<Card> & deck ){
    // randomly generate a number corresponding to a card in the deck
    size_t min_deck_index = 0;
    size_t deck_size = deck.size();
    size_t max_deck_index = deck_size - 1 ; // subtracts 1 from the size of a std::vector<Card> in order to get the index of the last card in the deck
    size_t rand_card_index = min_deck_index + rand() % (max_deck_index- min_deck_index+ 1); // equation for generating a random number between min_deck_index and max_deck_index, inclusive
    Card card_drawn = deck[rand_card_index]; //chooses a card in the deck, based on the randomly generated index
    deck.erase(deck.begin()+rand_card_index); //remove the card

    return card_drawn;
    
}

void showHand (int hand_val, const std::vector<Card> & hand){
    std::cout << "Hand value is: "<<hand_val<<"\n";
    std::cout << "Hand is:";
    for (Card current_card : hand){ // prints out each card in the inputted hand
        hand_val+=cardValue(current_card); // increases the total hand value by the value of the current card in the hand being iterated
        std::cout<<" "<< current_card.card_as_string(); // prints out a given card's identity as a string
    }
    std::cout<<"\n";
}


bool exceeds(int hand_up_bound, int current_hand_val){
    if (hand_up_bound<current_hand_val){ //returns true only if the current hand value has been exceeded
        return true;
    }
    else{
        return false;
    }
}


bool inRange(int hand_low_bound, int hand_up_bound, int current_hand_val){
    if (hand_low_bound <= current_hand_val && current_hand_val <= hand_up_bound){ //returns true only if/when the hand value is within the target range
        return true;
    }
    else{
        return false;
    }
}




