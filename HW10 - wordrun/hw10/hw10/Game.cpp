//
//  main.cpp
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

using namespace std;
int main(){
    
    srand(time(nullptr)); // seeds the random number generator used by the WordRun class
    
    // Checks to see if the user has save data. If they do, then their best score is returned. Otherwise, telss the user that they have not played yet
    string user_name;
    cout << "Enter your name: ";
    getline(cin,user_name);
    string filename = "/Users/lanceaquino/Desktop/PIC10A/HW10 - wordrun/hw10/hw10/" + user_name + ".txt"; // shorten to the last bit in the final product
    ifstream user_info (filename);
    if (!user_info){ // if the input file stream fails, then the file for the user's information does not exist, meaning that the user has not played before
        cout << "You have not played before.\n";
    }
    else { // if the file for the user's information exists, tells the user their best score out of all their recorded scores.
        int current_score;
        int best_score = 0; // this represents the int that will store the user's best score as the file is iterated through
        while (user_info >> current_score){ // iterates all scores stored in the file containing the user's previous scores, given that they have any existing data.
            if (current_score > best_score){ // if the score being checked is greater than the previous value stored in best_score, changes best_score to be the value of current_score
                best_score = current_score;
            }
        }
        user_info.close();
        cout << "Your best score is " << to_string(best_score) <<".\n";
    }
    
    // prompts the user for the option to play the game
    string play_game = "y";
    cout << "Would you like to play? y/n:";
    getline(cin, play_game);
    if (play_game == "n"){ // if the user selects "n", they don't want to play the game and the file for the game ends
        cout << "goodbye";
        return 0; // ends the game after saying "goodbye" if the user selects "n"
    }
    
    else{ // if the user opts into playing, the file tells the user the rules, and the game begins
        WordRun wrgame = WordRun();
        cout<<"(Don't look, but the winning word is "<< wrgame.randword() << "\n"; //remember to remove randword() before the final product
        cout << "Try to guess a 4-letter word. Letters in their rightful place get a ’*’. Letters of the word not in their place get a ’~’. Otherwise, a ’-’ is displayed.\n";
        
        string word_guess;
        while (! wrgame.hasWon()){ // keeps going as long as the user has not yet changed the value of won to true, or while they haven't won yet
            getline(cin, word_guess); // takes an input for the user's guess
            wrgame.guess(word_guess); //calls the guess function on the user's guess, which increments the number of guesses taken, determines if the user's input is valid, then prints a message or hint based on the user's input
            cout << '\n';
        }
        
        // when wrgame.hasWon == true, the previous while loop breaks and the end of game routine executes, which tells the user their number of guesses, the time they took, and their final score based on these metrics
        string score = to_string(wrgame.getScore());
        string time_taken = to_string(wrgame.getTime());
        string guesses_taken = to_string(wrgame.getGuesses());
        cout << "You won and responded in "<< guesses_taken<< " guesses, with a time of "<< time_taken << "s, earning a score of " << score << "." ;
        
        // Updates the user's info. If the user's file exists, then their file is appended with the score
        ofstream new_user_info (filename,  std::ios_base::app );
        new_user_info << score <<"\n"; // appends the score from this game to the file corresponding to the user's score information. The newline char is so that there is whitespace between scores so that the the next score isn't get appended immediately after the previous score, resulting in errors when reading the score of the file again
        new_user_info.close();
    }
    return 0;
}
