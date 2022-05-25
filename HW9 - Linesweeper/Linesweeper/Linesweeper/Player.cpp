//
//  Player.cpp
//  Linesweeper
//
//  Created by Lance Aquino on 3/5/22.
//

#include <string>
#include "Player.h"

//Player constructor that accepts a std::string for the user's name and returns a Player class storing the user's inputted name as well as their best score, which is initialized as 0
Player::Player(std::string _name) :
    name (_name), // name value set to the first argument of the Player constructor
    bestScore(score_zero) // initializes the player's score as 0
{}

// Member functions

const bool Player::checkRecord (const int recent_score){
    if (recent_score > bestScore){ // only overwrites the Player class' bestScore if the inputted score is greater, then returns the bool true
        bestScore = recent_score;
        return true;
    }
    else{  // otherwise, the Player class' bestScore remains constant and returns the bool false
        return false;
    }
}

// Getter functions for the values stored in a Player class

const std::string Player::getName(){
    return name;
}

const int Player::getMaxScore (){
    return bestScore;
}


