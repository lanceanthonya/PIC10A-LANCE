//
//  Player.h
//  Linesweeper
//
//  Created by Lance Aquino on 3/5/22.
//

#include <string>

#ifndef __PLAYER__
#define __PLAYER__

/**
 @class Player stores the user's inputted name as well as their all time high score.
 */
class Player{
    
public:
        
/**
 Constructor: Accepts an std::string for the user's name and generates a Player class storing the user's inputted name as an std::string as well as their best score, which is initialized as 0

 @param _name a string containing the user's name
 */
    Player (std::string _name);
    
/**
 Getter function that returns a Player Class' name value as a const std::string
 
 @return a string representing the name stored in a given Player class
 */
    const std::string getName();

/**
 Getter function that returns a Player Class' bestScore value as a const int

 @return an int representing the bestScore value stored in a given Player class
 */
    const int getMaxScore ();
/**
 Member function that checks if a Player Class' bestScore value is greater than the score int inputted into the function. Returns true and updates the Player's score to the recent score if the recent score is greater, otherwise returns false
 
 @param recent_score some int representing a user's recent score
 
 @return true if recent_score>bestScore, false otherwise (if recent_score <= bestScore)
 */
    const bool checkRecord (const int recent_score);

private:

const int score_zero = 0; // the score of a Player class is always initially 0

std::string name; // some string representation of the user's inputted name

int bestScore; // represents the score of the player. Only modified by checkRecord

};

#endif 
