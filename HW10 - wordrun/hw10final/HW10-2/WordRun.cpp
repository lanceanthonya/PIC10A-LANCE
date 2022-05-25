//
//  WordRun.cpp
//  hw10
//
//  Created by Lance Aquino on 3/12/22.
//

#include "WordRun.h"
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <cstdlib>
#include <ctime>
#include <algorithm>

WordRun::WordRun():
words(),
chosen(),
chars(), // represents the 4 characters in std::string chosen
guesses(0),
start(time(nullptr)), // initial time is that of the number of secs since Jan 1, 1970, or the time when the constructor is called.
duration(), // the final duration will be the time when the user selects the right answer and getTime() is called - the time when the constructor was called
won (false),
score(score_zero)
{
    setWords();
    chooseWord();
}
void WordRun::setWords(){
    std::ifstream wrdoth( "word4.txt"); // opens an ifstream to the file "word4.txt: to get the list of all possible words for the game
    std::string flword; // string that will receive inputs from the filestream to word4.txt
    while (wrdoth >> flword){ // as long as word4.txt has words to add to the set, the loop runs
        words.insert(flword); // the word from word4.txt will be added to the set
    }
    wrdoth.close(); // closes the file stream
    
}

void WordRun::chooseWord(){
    int times_to_randomly_iterate_thru_set = rand()%words.size(); // generates a random number corresponding to how many times the while loop will go through the set until it stops. The word found when the number of times to iterate through the set is 0
    auto iterator = words.end(); // corresponds to a pointer pointing to the final word in the set. The while loop moves the pointer backwards until the times_to_randomly_iterate_thru_set is finished.
    
    while (times_to_randomly_iterate_thru_set  > 0){ // times_to_randomly_iterate_thru_set decreases until 0, which means that the final item in the set to use as the "random" word has been reached
        --times_to_randomly_iterate_thru_set;
        --iterator; //starting from words.end(), moves the pointer away from the end by 1 for each round of times_to_randomly_iterate_thru_set
    }
    std::string random_word = *iterator; // creates a string representing the word in the std::set<std::string> words that the pointer "iterator" lands on
    chosen = random_word; // sets the chosen to be whatever word was chosen in the last line
    for (char character : random_word){ // populates the std::vector<char> chars with each character of the chosen word, in the order that they appear in the word.
        chars.push_back(character);
    }
}

void WordRun::guess(const std::string & user_guess){
    
    ++guesses;//increments the number of guesses, whenever a user-inputted guess is checked
    std::string copy_of_user_guess = user_guess;
    std::string guess_hint = "----"; // generates a string where no hints have yet been given (all chars are '-')
    auto checker = words.find(copy_of_user_guess); // checks to see if the word is present in the set created from all the words in word4.txt
    if (copy_of_user_guess.size() != chosen.size()){ //checks to see if the word is wrong size (input.size() != chosen.size())
        std::cout << "wrong size";
    }
    else if (checker == words.end()){ // checks to see if the input does not match any possible words from word4.txt
        std::cout <<"word not among possible words";
    }
    else{ // otherwise, if the word is present in the set, then it changes the hint string based on what the hint should look like
        
        //check characters to see if inputted guess' chars is in the correct spot or if the char is present in the answer but in the wrong space. ’-’ is displayed if it matches nothing, '*' if it's in the right spot , and '~' if the charactrer is present but in the incorrect spot
        
        std::vector<char> chars_in_guess; //creates a vector containing all chars in the user's guess, in the order that the characters appear
        for (char characters : copy_of_user_guess){ // populates the vector corresponding to the user's guess
            chars_in_guess.push_back(characters);
        }
        size_t final_char_index = chars_in_guess.size() - 1; // represents the final character index for both the guess and the answer, which at this point should have the same length/size
        size_t first_char_index = 0; // represents index 0, or the first index in the iterables
        
        //Checks each character in the guess to see if it matches any character in the answer by replacing it with '~' first
        for (size_t guess_char_index = first_char_index ; guess_char_index <= final_char_index ; ++guess_char_index){ // main loop iterates through each character of the guess
            for (size_t answer_char_index = 0 ; answer_char_index <= final_char_index; ++ answer_char_index){ //secondary loop iterates through each character of the answer, to see if the character in the guess matches it
                if (chars_in_guess[guess_char_index] == chars[answer_char_index]){
                    guess_hint[guess_char_index] = '~'; // if the character matches any char in the answer, it overwrites the char in the hint string to be a '~', then stops searching the answer char string
                    break;
                }
            }
        }
        for (size_t current_char_index = first_char_index ; current_char_index <= final_char_index ;++ current_char_index){ // iterates through characters in both vectors chars and chars_in_guess to see if at a given position, the user's guess and the answer's character are the same character. If a character was initially a ~, it will be replaced with an "*" here to signify this
            if (chars_in_guess[current_char_index] == chars[current_char_index]){ // if the chars at a given position are the same for both the answer and the guess, replaces whatever hint character was there with '*'
                guess_hint[current_char_index] = '*';
            }
        }
    std::cout <<guess_hint;
    }
    if (guess_hint == "****"){// if the user's guess matches the answer entirely, they have won and won is set to true
        won = true;
        duration = getTime(); // for some reason, when getTime() is executed, duration isn't overwritten. This redundancy is to ensure that duration is changed by this function
        setScore(); // determines score only if the win state is achieved
    }
}


const int WordRun::getTime(){
    if (won){ // if the user has won and the current game is over
        time_t final_time = time(nullptr); // gets the time as of this function call. Should be greater than the time stored in time_t start, which as called at the beginning of the game
        duration = final_time - start; // the final duration will be the time when the user selects the right answer and getTime() is called - the time when the constructor was called
        return duration; // this duration calculated is returned as an int
    }
    else{ // if the user has not yet won and the current game continues
        int time_if_not_won = -1;
        return time_if_not_won;
    }
}

const int WordRun::getGuesses(){
    if (won){ // if the user has won, the number of guesses stored in the WordRun class is returned
        return guesses;
    }
    else{ // otherwise, the function returns -1, as told by the guidelines
        int guesses_if_not_won = -1;
        return guesses_if_not_won;
    }
}

const int WordRun::getScore(){
    if (won){ // if the user has won, their score (which should only have been changed by setScore()) is returned
        return score;
    }
    else { // otherwise, the function returns -1, as told by the guidelines
        int score_if_not_won = -1;
        return score_if_not_won;
    }
}


const bool WordRun::hasWon(){
    return won; //simply returns whether or not the game is over as a bool. If true, the game is over and the user has won, otherwise false and the game continues
}

void WordRun::setScore(){
    int time_limit = 150; // if time or the number of guesses go over these values, then the corresponding scores are returned as 0
    int guess_limit = 150;
    int min_time_score = 0; //scores that represent the score of each type if the number of guesses or time taken exceeds the time or guess limit values
    int min_guess_score = 0;
    
    int time_taken = static_cast<int>(duration); // gets the time that the user took in order to find the correct answer.
    int TimeScore = std::max(min_time_score,time_limit - time_taken); // calculates the time score. If the time goes over time_limit seconds, then the TimeScore is 0
    int GuessScore = std::max(min_guess_score, guess_limit-guesses);  // calculates the guess score. If the number of guesses goes over guess_limit, then the GuessScore is 0
    score = TimeScore + GuessScore;
}
