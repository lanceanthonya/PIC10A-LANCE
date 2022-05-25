//
//  WordRun.h
//  hw10
//
//  Created by Lance Aquino on 3/12/22.
//

#include <ctime>
#include <set>
#include <string>
#include <vector>

#ifndef __WORDRUN__
#define __WORDRUN__

/**
 @class WordRun A set of information for the game WordRun, which randomly generates a 4-letter word for the user to guess. Also generates a score based on the time the user took to find the correct word, as well as the number of guesses they made in order to find this word.
 */

class WordRun{
public:
    /**
     Constructor that generates a WordRun game, including the a random 4-letter word out of a list of 4-letter words "word4.txt",  records the start time, and begins recording the user's number of guesses. Doesn't take any user-inputted parameters
     */
    WordRun();
    
    /**
     Accessor function that returns whether or not the user has won the current game of WordRun
     
     @return the state of the game. If false, the game is not over.  If true, then the game is over
     */
    
    const bool hasWon();
    
    /**
     Accessor function that returns the user's overall score for the game. -1 If the game has not been won yet
     
     @return An int representing the user's final score
     
     */
    const int getScore();
    
    /**
     Returns the number of seconds the user has taken. -1 if the game has not been won yet
     
     @return The number of seconds the user has taken between the constructor being called and this function being called
     */
    
    const int getTime();
    
    /**
     Accessor function returning the number of guesses the user has taken, or -1 if the game has not been won yet
     
     @return the number of guesses the user took to get the right answer, including their final guess that matched the anwer
     */
    
    const int getGuesses();
    
    /**
     Given an std::string representing the user inputted guess for the answer, then handles the hint-giving and checking of the input. Prints messages based on whether the user's input is valid as well as a string of chars that represent the hint for the answer, as outlined by the game rules.
     
     @param user_guess some string of letters that corresponds to the user's attempt at determining the answer to a given game of WordRun.
     */
    
    void guess(const std::string & user_guess);
    
private:
    
    std::set<std::string> words; // a set containing all possible 4-letter words that std::string chosen could be, as well as all possible valid guesses
    std::string chosen; // string that represents the randomly selected word
    std::vector<char> chars; // represents the 4 characters in std::string chosen
    int guesses; // how many guesses the user has made so in a given
    time_t start; // time_t value representing the time when the game started, in secs
    time_t duration; // time_t value representing the total amount of time the game took, in secs
    bool won; //state of the game. True if the user has triggered the win condition in guess(), false if otherwise
    int score; // the user's calculated score at the end of the game.
    const int score_zero = 0; // score before the game has started. 0 By default
    
    /**
     Generates the std::set<std::string> words, based on the file word4.txt. Contains all possible words that the answer could be, as well as the pool of words from which the  user can guess from
     */
    
    void setWords();
    
    /**
     Randomly chooses a word (std::string chosen) and populates a member vector storing its characters in the same order(std::vector<char> chars)
     */
    
    void chooseWord();
    
    /**
     Function that calculates the user's overall score for the game, given the time it took for them to complete the game and the number of guesses. Only called by guess()
     */
    
    void setScore();
    
};


#endif
