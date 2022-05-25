#include <iostream>
#include <vector>
#include "Player.h"
#include "LineOfMines.h"
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;
int main() {

    srand(time(nullptr)); // random number generator is seeded based on time

	// The game is explained
	cout <<
		"This is a game of Linesweeper: mines are arranged on a line. \n"
		"You select a position to reveal what is there. \n"
		"For every safe location you reveal, you get +1 point. \n"
		"If you reveal a mine, you get a score of 0. \n"
		"A given location may have a mine to either its left, right, both, or neither. \n"
		"The number of neighbouring mines of a revealed location 0/1/2 is displayed. \n"
		"You can continue playing until you either hit a mine or choose not to reveal any more locations." << '\n';
    
    // The setup routine for the game, which accepts user inputs for player name, number of locations, and number of mines
    
    string inputtted_player_name;
    int inputted_line_length, inputted_num_mines;
    cout << "What is your name? ";
    getline(cin,inputtted_player_name); // getline() used in case the user inputted name contains spacess
    cout << "How long do you want the line? ";
    cin >> inputted_line_length;
    cout << "How many mines do you want on the line? ";
    cin >> inputted_num_mines;
    
    Player user = Player(inputtted_player_name); // generates a player class based on the inputted name
            
    string continue_game = "y"; // variable that determines whether the game should continue or not. editted by user input at the end of each iteration of the main while loop
    
    int user_position_input;
    
    while (continue_game  == "y"){ // main game loop that continuess as long as the state of continue_game remains "y"
        
        LineOfMines Linesweeper_simulation = LineOfMines(inputted_line_length, inputted_num_mines); // Creates a LineOfMines class for the Linesweeper game, based on the user's inputs for number of mines and lines. Creates a new LineOfMines simulation before each round begins, therefore re-randomizing the mine locations and resetting all of the positions to their unrevealed state "_____".
        
        string continue_round = "y"; // string that gets overwritten by inputs during the round loop that represents whether or not a given round should continue. reset to "y" before each round
        
        Linesweeper_simulation.display(); // will show the initial states of locationDisplays, which should all be "_____" at this point
        cout << "\n";
        
        while(continue_round == "y"){ // loop for one round
            
            cout << "What position location would you like to reveal? ";
            cin >> user_position_input; // the user enters a number between 1 and lineLength
            Linesweeper_simulation.makeSelection(user_position_input); // checks if the user has triggered a mine. the corresponding position in locationDisplays is checked and updated, based on whether a mine has been triggered or how many mines are adjacent to that position. hasHitMine() will return true if they HAVE selected a mine through their input, false if they HAVEN'T
            
            if (!Linesweeper_simulation.hasHitMine()){ // if the user HASN'T triggered a mine, the user's score for the round increments and the display is updated and printed
                Linesweeper_simulation.display();
                cout << "\n";
            }
            else { // if the player has triggered a mine, then all mine positions for the round are revealed and the round loop breaks
                cout  << "The mine positions are now revealed: \n";
                Linesweeper_simulation.grandReveal();
                cout << "\n";
                break;
            }
            
            cout  << "Would you like to reveal another location? [y/n] "; // as long as the player hasn't triggered a mine, prompts them to determine whether or not they would like to reveal another location
            cin >> continue_round;
            if (continue_round == "n"){ // if the user decides not to continue the round, then the mine locations are revealed. However, since the hitMine member variable should still be false, the player's score is not 0 when thhe user chooses this option
                cout << "The mine positions are now revealed: \n";
                Linesweeper_simulation.grandReveal();
                cout << "\n";
                break;
            }
        }
        
        int round_score = Linesweeper_simulation.getScore();
        if (user.checkRecord(round_score)){ // If the player's score for a round is greater than their all time record high score, it gets updated and the function checkRecord returns true
            cout << "You have a new high score of " << round_score << "!\n";
        }
        else{ // otherwise, the user's score is not updated and the game tells them their score for the round as well as their current all time high score
            cout << "You scored " << round_score << ", but your best score is still " << user.getMaxScore() <<"\n";
            
        }
        cout << "Would you like to play another game? [y/n] "; // prompt for whether or not the main loop continues
        cin >> continue_game;
    }
    
    cout << "\n" <<user.getName() << ", your top score was " << user.getMaxScore(); // Refers to the player by the inputted name stored in the Player class, and tells them their overall all time highest score
	
	return 0;
}
