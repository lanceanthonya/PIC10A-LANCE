//
//  main.cpp
//  HW6
//
//  Created by Lance Aquino on 2/12/22.
//

#include <iostream>
#include <string>
#include "Card.h"
#include "Range.h"
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
    
    srand(time(nullptr));  // generates a seed for the random number generator based on time
    
    // initial game message that explains the rules of the game
    cout << "Cards 2-10 are worth their numeric value. \n"
    <<"J, Q, K have a value of 11.\n"
    <<"An A has a value of 12 as a spade and 1 for other suits.\n"
    <<"Over 3 rounds, you will try to reach or exceed a target value, without going over 22!\n"
    <<"If you go over, you get -1 points; if you are within range, you get +1 points; otherwise you get 0 points.\n\n";
    
    signed player_score = 0; //the user's total score starts off as 0. Gets overwritten each round
    const int min_lower_bound = 17; //min possible lower bound, used for the random number generator
    const int upper_bound = 22; // max possible lower bound in the range, used for the random number generator
    
    // main game loop, each round out of 3 is one iteration through the loop
    for (int round = 1 ; round <=3 ; ++round){
        
        //Some values that are set or reset at the start of each round
        int lower_bound = min_lower_bound + rand() % (upper_bound - min_lower_bound+ 1); // randomly generates and sets the lower bound before the start of each round. It will be between min_lower_bound and upper_bound, inclusive
        vector<Card> game_deck = create_deck(); //Resets the deck of cards to draw from before the start of the round, should have size_t of 52
        vector<Card> user_hand;
        int user_hand_val = 0; // the user's hand starts off as 0
        
        // Loop for a given round that runs for as long as the value of the user's hand has NOT exceeded the upper bound (22)
        while (!exceeds(upper_bound,user_hand_val)){
            
            cout<< "Target lower bound: " << lower_bound<<"\n";
            
            //A card is dealt and added to the user's hand. That same card is removed from the game deck
            Card new_card = dealCard(game_deck); // deals a card and removes it from the g
            user_hand.push_back(new_card);
            
            //Calculates the current value of the user's deck and prints it, along with the cards present in said deck
            user_hand_val += cardValue(new_card);
            showHand(user_hand_val,user_hand);
            
            //Determines whether the user has lost or won the current round, to update their score and end the loop for the round
            if (exceeds(upper_bound,user_hand_val)){ // if the user's deck value exceeds the upperbound, they lose the round
                player_score -= 1; //user's total score decreases, as they add -1 points to their total score
                cout<<"You got -1 points.\n\n";
                break;
            }
            else if (inRange(lower_bound,upper_bound,user_hand_val)){//if the user's deck value is in range of the lower and upper bound for the round, they win the round
                player_score +=1;  //user's total score increases, as they gain 1 point to their total score
                cout<<"You got 1 point.\n\n";
                break;
            }
            
            // If the user has not won or lost the round yet, asks if the user would like to receive another card
            string user_input;
            cout <<"Deal more? y/n: ";
            cin >> user_input;
            if (user_input == "y"){/*empty*/} // goes back to the start of the loop if the user inputs "y". No code executed
            else if (user_input == "n" ){ // if the user declines another card, they receive 0 points for the round and the current round ends
                cout<< "You got 0 points.\n\n";
                break;
            }
        }
    }
    //prints the user's final score. either plural or singular, based on the user's total score
    cout << "\nYour total score is ";
    if (player_score == 1){ // "point" singular is used only if the total score was 1
        cout << "1 point.";
    }
    else{ //otherwise, if the user's score was any other value, then "points" plural is used
        cout<< player_score << " points.";
    }
    
    return 0;
}

