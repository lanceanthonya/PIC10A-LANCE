//
//  CI.h
//  CI
//
//  Created by Lance Aquino on 3/16/22.
//

#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

#ifndef __CI__
#define __CI__

/**
 @class A
 */
class CI_String{
public:
    
    /**
     Constructor that accepts a  string, possibly with a mix of uppercase and lowercase letters
     
     @param in_str some string that may contain any possible ascii characters. The string will be modified such that all alphabetic characters are lowercase
     */
    CI_String(const std::string & in_str);
    
    /**
     Function that returns the value of str
     
     @return a CI_String's str value
     */
    std::string get_string() const;
    
    
    /**
     Function that returns the size of str
     
     @return the size of the member variable str
     */
    size_t size() const;
    
private:
    std::string str; // some string containing only lower case letters, based on the input from the constructor

};


/**
 Receive an std::string as an input and returns an std::string with all the letters lowercase.
 
 @param in_str some string containing a mix of uppercase and lowercase letters
 
 @return a string with all the chars in in_str lowercase
 */

std::string make_lower(const std::string& in_str);

/**
 Overload of operator<< that allows for a CI_String object to be outputted
 
 @param oss output stream
 @param output_ci_str the CI_String to output
 
 @return output stream containing the str value stored in the CI_String object
 */
std::ostream& operator<<( std::ostream& oss, const CI_String& output_ci_str);

/**
 Overload of operator< that allows for two CI_String objects to be compared
 
 @param ci_str_1 some CI_String to be compareed
 @param ci_str_2 some CI_String to be compared
 
 @return true if ci_str_1 is less than ci_str_2, false otherwise
 */
bool operator<( const CI_String& ci_str_1, const CI_String& ci_str_2);

/**
 Returns the total number o f characters in a file, including whitespace characters
 
 @param filename the name of some file, in .txt form
 
 @return the total number of chars in that file
 */
size_t total_chars(const std::string &filename);

/**
 Returns a set containing all unique "words" in a file
 
 @param filename a string representing a file containing words
 
 @return a set containing all unique "words" in a file, where a word is some continuous sequence of non-whitespace characters.
 */
std::set<CI_String> unique_words(const std::string & filename);

/**
 Returns a std::vector<int> containing the number of unique "words" per line in a file
 
 @param filename a string representing a file containing words
 
 @return a vector containing the number of unique words per line.  The 0th index will represent the number of unique words in the first line of the file, while the final index represents the number of unique words in the last line of the file
 */
std::vector<size_t>uniques_per_line(const std::string & filename);

/**
 A function printing each unique word of line 1 in a given file in lexicographic order with its multiplicity. As words are printed/displayed, only their all-lowercase representation should be displayed.
 
 @param filename the name of a file
 */
void print_line_one_info(const std::string & filename);


#endif 
