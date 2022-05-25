//
//  LineOfMines.cpp
//  Linesweeper
//
//  Created by Lance Aquino on 3/5/22.
//

#include "LineOfMines.h"
#include <string>
#include <vector>
#include <stddef.h>
#include <iostream>
#include <cstdlib>
#include <iomanip>

LineOfMines::LineOfMines(size_t _lineLength, size_t _numberOfMines) :
    lineLength (_lineLength), // setting the length of the line and number of mines based on user input
    numberOfMines(_numberOfMines),
    score (score_zero), // the score of a game is 0 by default
    locationDisplays (std::vector<std::string>(_lineLength , "_____" )), // generates a vector containing the initial displays of the locations in the game, each starting as "_____", indicating an untouched space
    neighbouringMineCounts(std::vector<int>(lineLength , 0)),
    mineLocations(std::vector<int>(numberOfMines , 0)),
    hitMine (false) // by default, the state for no mines being activated is false

{
    placeMines(); //changes the initial 0's in mineLocations into randomly generated ints that correspond to indeces of locationDisplays
    setCounts(); // calculates the number of neighboring mines for each index in the std::vector<int> neighbouringMineCounts
}

// Some member functions

void LineOfMines::display(){
    
    for (size_t current_num = 1 ; current_num <= lineLength; ++current_num){ // generates the positions to display on the console that the user can choose from, in order to reveal whether or not that position corresponds to a mine or a safe space
        std::cout << std::left << std::setw(5) << current_num << " ";
    }
    std::cout << "\n";
    for (std::string current_line : locationDisplays ){ // generates all the locations, with their current state. By default, they are all empty and get modified as the user plays the game and inputs locations
        std::cout << current_line << " ";
    }
}

void LineOfMines::placeMines(){
    
    int maxindex = lineLength - 1; // the largest possible index of the display vector, based on the lineLength of the class
    std::vector<int> possible_indeces_vector; // a vector that contains all possible indeces, from 0 to maxindex
    
    for (size_t possible_index = 0; possible_index <= maxindex ; ++possible_index ){
        possible_indeces_vector.push_back(possible_index); // populates a starting vector with all from ints 0 through lineLength-1
    }
    shuffle(possible_indeces_vector); // shuffles or randomly moves around a vector containing all possible location numbers
    
    size_t last_mine_index = numberOfMines - 1; // represents the index at which the code stops taking values from the shuffled possible_indeces_vector to put into inserted_vector
    for (size_t mine_location_index = 0 ; mine_location_index <= last_mine_index; ++mine_location_index){ // for each index within inserted_vector and possible_indeces_vector from 0 to the last_mine_index
        mineLocations [mine_location_index] = possible_indeces_vector[mine_location_index]; // replaces the 0's in the inserted_vector with the first numberOfMines ints from possible_indeces_vector in order to set the randomized mine locations for the class
    }
}

bool LineOfMines::containsMine (const int position){
    
    int index = position - 1; // converts an inputted position number (from the user interface) into an index between 0 and locationDisplays.size()-1, since mineLocations contains values in terms of indeces from 0 to lineLength-1
    for (int mineLocation_index : mineLocations ){ // iterates through each value in mineLocations, checking to see if the value of the index being checked matches any values contained in it
        if (index == mineLocation_index){ //  If the inputted index matches any numbers within mineLocations, the function returns true, otherwise the loop continues its search
            return true;
        }
    }
    return false; // if the for loop finishes iterating and no matches have been found, then the function returns false
}

void LineOfMines::grandReveal(){
    
    for (int mine_location : mineLocations){ // iterate through each mine locations in the vector<int> mineLocations, each iteration modifying a value in locationDisplays into "__*__"
        locationDisplays[mine_location] = "__*__";
    }
    
    display(); // displays locationDisplays, now with each position that contained a mine replaced with "__*__"
}

void LineOfMines::setCounts(){
    
    size_t zero_pos = 0;
    size_t final_pos = neighbouringMineCounts.size()-1;
    
    for (int mine_index : mineLocations){
        if ((zero_pos < mine_index)&&(mine_index < final_pos)){ // checks to see if the current mine_index is 0 or the final index
            neighbouringMineCounts[mine_index+1] +=1; // increments the index to the right of  the current index
            neighbouringMineCounts[mine_index-1] +=1; // increments the index to the left of the current index
        }
        else if  (mine_index == zero_pos){ // if the current mine_index is 0 (corresponding to the first/left-most position) then only the count at the index immediately to the right of it is incremented since there is no index to the left of it
            neighbouringMineCounts[mine_index+1] +=1;
        }
        else if (mine_index == final_pos){ // if the current mine_index is final_pos (corresponding to the final/right-most position) then only the count at the index immediately to the left of it is incremented since there is no index to the right of it
            neighbouringMineCounts[mine_index-1] +=1;
            
        }
    }
}


const int LineOfMines::getScore(){
    
    if (hasHitMine()){ // if the user has triggered a mine, then their score is immediately changed to 0 and this is the score value thhat gets returned
        score = score_zero;
        return score;
    }
    else {
        return score; // otherwise, the user's score for a round at the time getScore() gets called is returned
    }
}

const bool LineOfMines::hasHitMine(){
    
    return hitMine;
}

// Some Private functions that are only used by other member functions of a LineOfMines class

void LineOfMines::swap (int& first_num, int& second_num ){
    
    int copy_of_first_num = first_num; // creates a copy of the first number before it is overwritten
    first_num = second_num;
    second_num = copy_of_first_num;
}

void LineOfMines::shuffle (std::vector<int>& vector_of_locations){
    
    size_t final_index = vector_of_locations.size() - 1; // final index of a vector is its size - 1
    for  (size_t current_index = 0; current_index < final_index; ++current_index){ // iterates through all the possible location numbers
        swap(vector_of_locations[current_index],  vector_of_locations[rand() % (final_index + 1 )]);  //  swaps a given location number with another randomly selected location number from 0 to final_index
    }
}

void LineOfMines::makeSelection(const int inputted_position){
    
    int index = inputted_position - 1; // The corresponding index of an inputted position is this, because the user interface starts from 1 instead of 0
    
    if( containsMine(inputted_position)) { // checks to see if the inputted position's index corresponds to a mine location in the std::vector<int> mineLocations
        hitMine = true;
        locationDisplays [index]  = "__*__";
    }
    else{ // otherwise,
        std::string num_mines = std::to_string(neighbouringMineCounts[index]);
        std::string altered_location_space = "__" + num_mines + "__";
        score +=1;
        locationDisplays [index] = altered_location_space;
    }
}

