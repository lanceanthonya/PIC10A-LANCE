//
//  CI.cpp
//  CI
//
//  Created by Lance Aquino on 3/16/22.
//

#include "CI.h"
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>


// Constructor of CI_String

CI_String::CI_String(const std::string & in_str):
str(make_lower(in_str))
{}

// Member functions of CI_String

std::string CI_String::get_string() const {
    return str;
}

size_t CI_String::size() const{
    return str.size();
}

// Free functions / overloaded operators

std::string make_lower(const std::string& in_str){
    
    std::string out_str  = in_str; // creates a copy of the inputted string to change the characters of during the loop
    
    // Values of certain chars used for determining if a given char is upper case and (if so) converting it to lowercase
    char ascii_A = 'A';
    char ascii_Z = 'Z';
    char ascii_a = 'a';
    
    size_t fin_index = out_str.size() - 1;
    
    for (size_t current_index = 0; current_index <=fin_index; ++current_index ){ // iterates through the inputted string, from very first character on the left, to the very last character on the right
        char current_char = in_str[current_index]; // current char to be checked for case
        if ( ascii_A <= current_char && current_char <= ascii_Z){ // checks if the current character is uppercase, by comparing its ascii value to the ascii values of the first and last chars 'A' and 'Z'
            out_str[current_index] = (current_char + ascii_a) - ascii_A; // if current_char is uppercase, this equation converts it to a lowercase
            
        }
    }
        
    return out_str; // final string that should have all alphabetic characters lowercase
}

std::ostream& operator<<( std::ostream& oss, const CI_String& output_ci_str){
    std::string output_str = output_ci_str.get_string(); // the value of str to be inserted into the oss
    oss << output_str;
    return oss;
}


bool operator<(const CI_String& ci_str_1, const CI_String& ci_str_2){
    
    
    // gets the strings stored in each CI_String's str value
    std::string ci_str_1_str = ci_str_1.CI_String::get_string();
    std::string ci_str_2_str = ci_str_2.CI_String::get_string();
    
    return ci_str_1_str < ci_str_2_str ? true : false; // compares the lengths of the CI_String items on both sides of the operator. If ci_str_1_str is lower in the string comparison than ci_str_2_str, this comparison returns true, otherwise, false
}

size_t total_chars(const std::string & filename){
    std::ifstream ifs(filename); // opens a file stream to the inputted
    char current_char; // the current char from the file stream to be included in the character count
    size_t total_chars = 0; // total number of chars starts at 0
    if (!ifs){ // if the file does not exist, total_chars=0 is returned
        return total_chars;
    }
    else{ // otherwise, the file is opened
        while (ifs.get(current_char) ){ // as long as a character can be extracted from the file stream, the value of total_chars increases by 1
            ++total_chars;
        }
        ifs.close();
    }
    return total_chars;
}

std::set<CI_String>  unique_words(const std::string & filename){
    std::set<CI_String> ci_string_set; // creates a set of CI_String values
    std::ifstream ifs(filename);
    std::string current_word;// the current word within the file to be added to the set
    if (!ifs){ // checks to see if the file exists/contains characters. Returns the empty set if it is empty/doesn't exist
        return ci_string_set;
    }
    else{ // otherwise, the file exist and the routine for checking for unique words continues
        while (ifs >> current_word){ // as long as words can be extracted from the file stream, they are extracted
            ci_string_set.insert(CI_String(current_word)); // the unique word will be added to the set as a CI_String. Does not add duplicated words
        }
        ifs.close();
    }
    return ci_string_set;

}

std::vector<size_t>uniques_per_line(const std::string & filename){
    std::vector<size_t> vector_of_uniques_per_line; // creates a vector where each number represents he number of unique words at a given line in the file
    std::ifstream ifs(filename);
    std::string current_line; // represents a "line" containing words, or all the words up to the point an \n is encountered
    if (!ifs){ // checks to see if the file exists/contains characters
        return vector_of_uniques_per_line; // returns the empty vector
    }
    else{
        while (std::getline(ifs,current_line)){ // while loop that iterates through each line in a txt file. getline() was used since it stops at each newline, which is good for our uses since we only want all the words up to the end of a line
            
            std::set<CI_String> unique_words_in_line; // set containing all unique words within a given line. Regenerated for each line in the file
            std::string current_word; // the current word within a line that is being checked for whether it should be added to the set counting unique words in a line
            std::istringstream iss (current_line); // creates a string stream to the current linee
            while (iss >> current_word){ // While there are still words in the line, the words are added to the set of all unique words
                unique_words_in_line.insert(CI_String(current_word));
            }
            size_t num_unique_in_line = unique_words_in_line.size();  // since the set contains all unique words in the line, the size of the set equals the number of unique words in said set

            vector_of_uniques_per_line.push_back(num_unique_in_line); // the value of the number of unique words in a line to the vector.
            
        }
        ifs.close();
    }
    return vector_of_uniques_per_line;
}

void print_line_one_info(const std::string & filename){
    std::map <std::string,int> word_and_its_multiplicity;  // creates a map that will store each unique word as well as how often it shows up within line 1 of the inputted file. It will be organized in lexicographic manner, by nature of it being a map
    std::ifstream ifs(filename);
    std::string line_one; // a string representing line_one of the file
    std::vector<std::string> all_words_in_line; // a vector containing all the words in one line as std::strings, all lowercase. Not yet sorted
    
    if (!ifs) {/*EMPTY*/} // checks to see if the file exists/contains characters. Nothing happens since this function relies on cout'ing things from the map, but if the file doesn't exist/is empty, then nothing gets cout'ed
    
    else{ // otherwise, if the file exists, then the routine for couting the appropriate messages occurs
        
        std::getline(ifs,line_one); // Creates a files stream that gets the very first line in the opened file ( or all the words until the first '\n' is encountered) and enters it into the variable line_one
        ifs.close();
        
        std::istringstream iss (line_one); // generates a string strema based on line_one
        std::string current_word; // will be used for each word within line_one
        while (iss >> current_word){ // as long as line_one has words that can be accepted, the map adds the value to a vector containing all words in the line, including repeats
            std::string possible_unique_word =CI_String(current_word).get_string();
            all_words_in_line.push_back(possible_unique_word);
            
        }
        for (std::string unique_word : all_words_in_line){
            word_and_its_multiplicity[unique_word]++; // adds unique words to the map, and increments the value of its multiplicity within the line
        }
        for(const auto& word_and_mult : word_and_its_multiplicity){
            if (word_and_mult.second == 1){
            std::cout << word_and_mult.first << " occurs 1 time.\n";
            }
            else{
                std::cout << word_and_mult.first << " occurs " <<word_and_mult.second << " times\n";
            }
        }
    }
    

}
