//
//  main.cpp
//  HW6
//
//  Created by Lance Aquino on 2/12/22.
//
/*
#include <iostream>
#include "Card.h"
#include "Range.h"
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
    srand(time(nullptr)); // generates a seed for the random number generator based on time
    vector<Card> new_deck = create_deck(); //generates a card using create_deck()
    cout << "All cards: \n";
    for (Card current_card : new_deck){
        int current_card_val = cardValue(current_card);
        cout<< current_card.card_as_string()<< " = " << current_card_val<<"\n";
    }
    while (true){
        vector<Card> user_hand;
        for (int i = 1; i<=5;++i){ //generates a user hand with 5 random cards
            Card card_dealt = dealCard(new_deck);
            user_hand.push_back(card_dealt);
        }
        int hand_val = showHand (user_hand);
        cout << "The user's deck is worth " << hand_val << " points\n";
        if (exceeds(22,hand_val)){
            cout << "you're out of range.";
        }
        else{
            cout<<"you're in range";
        }
        size_t new_deck_size = new_deck.size();
        cout<<"\nThe user's deck now has "<< user_hand.size() <<" cards\n\n";
    }
    
    return 0;
    
    if (exceeds(22,22)){
        cout << "you're out of range.";
    }
    else{
        cout<<"you're in range";
    }
    
    return 0;
}


//Debugging code for Card dealCard()
cout <<"Number generated: "<< bounded_rand_int <<"\n"; //rng test
 
cout <<"Card Drawn: " << card_drawn.card_as_string()<<"\n"; //testing the identity of a card
 
Card top_card = new_deck[upp_b];
Card bot_card = new_deck[low_b];
cout<<"Top card in the pile: "<<top_card.card_as_string()<<"\n";
cout<<"Bottom card in the pile: "<<bot_card.card_as_string()<<"\n";
 
for (Card current_card : new_deck){ // iterator for a deck
    int current_card_val = cardValue(current_card); //gets the value of the current card in a deck as an int
    cout<< current_card.card_as_string()<< " = " << current_card_val<<"\n"; // prints a card and its value
 
size_t new_deck_size = new_deck.size(); //size of a deck
cout<<"The deck now has "<<new_deck_size <<" cards"; //
*/
