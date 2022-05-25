//
//  LineOfMines.h
//  Linesweeper
//
//  Created by Lance Aquino on 3/5/22.
//

#ifndef __LINEOFMINES__
#define __LINEOFMINES__

#include <string>
#include <vector>
#include <stddef.h>
#include <iostream>
#include <cstdlib>
#include <iomanip>

/**
 @class LineOfMines represents infformation used for the Linesweeper game simulation. A given LineOfMines contains inforamtion regarding the state of each position, the location of each mine
 */

class LineOfMines{

public:
    
    /**
     Constructor that accepts two size t inputs for the number of locations and number of mines, respectively. Using these inputs, this constructor sets lineLength and numberOfMines appropriately, sets score to 0, sets locationDisplays to a std::vector<std::string> of size lineLength all with value ”_____ ” (5 underscores), sets neighbouringMineCounts to a std::vector<int> of size lineLength each index containing the value 0, sets mineLocations to a std::vector<int> of size numberOfMines, all with value 0, sets hitMine to false. Afterwards, modifies neighbouringMineCounts and mineLocations by placing the mines in the game and setting the number of adjacent mines at each position.
     
     @param _lineLength how many possible locations in the game
     @param _numberOfMines how many mines are in play
     */
    
    LineOfMines(size_t _lineLength, size_t _numberOfMines);
    
    /**
     Getter function that returns the score value of a LineOfMines class
     
     @return the current score of the LineOfMines Class
     */
    
    const int getScore();
    
    /**
     Getter function that returns the boolean value of hitMine
     
     @return whatever bool is stored in the class member variable hitMine
     */
    
    const bool hasHitMine ();
    
    /**
     Member that displays the game board, including the number of each position, as well as the current state of said position.
     For example: at the start of a round, if a user inputted 10 for the line length, the console will output something like this:
     
     1     2     3     4     5     6     7     8     9     10
     _____ _____ _____ _____ _____ _____ _____ _____ _____ _____
     */
    
    void display();
    
    /**
     Member that sets the number of neighboring mines at all positions in the game by modifying ints in neighbouringMineCounts based on how many mines are adjacent to that given position. The only possible int values are 0, 1, and 2, where 2 is the maximum possible number of mines that can be adjacent to a given position. Also sets counts for positions corresponding with mines locations, but this doesn't matter since makeSelection() checks if a mine is located at a position before it changes that location's state to reflect the number of adjacent mines
     */
    
    void setCounts();
    
    /**
     Member function that modifies all  locationDisplays values with a mine designated by mineLocations to “ __*__ ” . subsequently calls display
     */
    
    void grandReveal();
    
    /**
     Accepting an int for the position a user wishes to reveal, updating the corresponding locationDisplays value to “__*__” if there is a mine present (and sets hitMine to true). Otherwise sets the value to one of "__0__" , "__1__" , or "__2__" , depending on how many mines are adjacent to a given position, as designated by the std::vector<int> neighbouringMineCounts.
     
     @param inputted_position an inputted number from 1 to locationDisplays.size() that the user would like to check
     */
    
    void makeSelection(const int inputted_position);
    
private:
    
    size_t lineLength; //number of locations in the game
    
    size_t numberOfMines; //  stores the number of mines
    
    int score_zero = 0; // refers to the initial score of the round, as well as the score if a user triggers a mine during a round
    int score; // stores the game’s score for the round.
    
    std::vector<std::string> locationDisplays = std::vector<std::string>(lineLength, "_____"); // vector representing the user interface, where each string represents the state of a given spot. Each spot should be "_____" by default
    
    std::vector<int> neighbouringMineCounts; // vector containing ints that correspond to how many mines are adjacent to a given position
    
    std::vector<int> mineLocations; // vector containing ints that correspond to indeces of mines. The index of a mine its corresponding position number-1 because the user interface shows numbers between  1 through locationDisplays.size(), while their indeces are 0 through locationDisplays.size()-1
    
    bool hitMine; // important state that determines whether or not the user has chosen position with a mine in it during a round
     
    /**
     Member that accepts an int between 1 and lineLength representing a position from the user interface in said range.
     
     @param position an inputted position to cross-reference with mineLocations
     
     @return true if the inputted int is contained within mineLocations, otherwise false
     */
    
    bool containsMine (const int position);
    
    /**
     places numberOfMines mines at distinct location indeces between 0 to lineLength-1 by modifying the std::vector<int> mineLocations. With all of its values initially being the value 0 numberOfMines times, each value in the vector is modified to be a random int between 0 and lineLength-1, or a random index from all possible indeces within the vector
     */
    
    void placeMines();
    
    /**
     Function used for swapping the values of two variablees storing integers. Used by the shuffle function to switch around ints in the std::vector<int> representing all possible indeces in the std::vector<std::string> locationDisplays, while shuffle() generates random indeces from its inputted vector
     
     @param first_num some variable storing an int that will then hold the value stored in the variable passed to second_num
     @param second_num some variable storing an int that will then hold the value stored in the variable passed to first_num
     */
    
    void swap (int& first_num, int& second_num );

    /**
     Function used to shuffle an inputted vector containing all possible locations of std::vector<std::string> locationDisplays, in order to create randomness and generate indeces that represent the locations of mines for mineLocations
     
     @param vector_of_locations some vector containing lineLength number of ints, each representing indeces of locationDisplays. vector_of_locations is expected to initially contain all possible indeces of locationDisplays
     */
    
    void shuffle (std::vector<int>& vector_of_locations);
    
};

#endif 
