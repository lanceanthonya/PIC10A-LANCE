#ifndef _NUMBERS_
#define _NUMBERS_

#include<string>
#include<cstddef>


/**
 Accepts a string representation of an unsigned integer in base 10 (or decimal) and outputs its equivalent binary number
 
 @param decimal_string a string representation of an inputted  unsigned integer, in base 10
 
 @return a string representation of that same unsigned integer but as a  binary number
 */
std::string decimalToBinary(const std::string & decimal_string);


/**
 Accepts a string representation of a binary number, and outputs its equivalent unsigned integer decimal number
 
 @param binary_string a string representation of a binary number (base 2)
 
 @return a string representation of the unsigned integer decimal number corresponding to the binary number inputted as binary_string
 */
std::string binaryToDecimal(const std::string & binary_string);


/**
 Given a string input, modifies the inputted string by rearranging the characters in the inputted string to be in the reverse order
 
 @param input a string of chars that gets overwritten as it gets reversed
 */
void reverseString (std::string & input);


/**
This function adds two unsigned integer types, represented as strings, given a base to work in.
The return format will be a sum, computed in whatever base is specified, where 2 <= base <= 10.

For example,
std::string sum1 = add("116", "14", 10); // sum1 == "130"
std::string sum2 = add("11", "10", 2); // sum == "101"

@param first the first addend
@param second the second addend
@param base the base being used: from 2-10

@return the sum, num1+num2 in the base
*/
std::string add(const std::string& first, const std::string& second, unsigned char base);


/**
This function takes a single character and returns an unsigned char for its value from 0-9

@param c the character to convert
@return its value from 0-9
*/
unsigned char charToDigit(char c);


/**
This function converts an unsigned char from 0-9 and returns a char '0' to '9'

@param u the unsigned char to convert
@return its digit representation as a char
*/
char digitToChar(unsigned char u);


/**
This function computes 2 to a given nonnegative integer power with the output as an std::string, in base 10

@param pow an integer representing the power of 2 to be calculated
 
@return a string the calculation of  2^pow
*/
std::string twoPower(size_t pow);


/**
This function subtracts two unsigned integer types, represented as strings, given a base to work in.
The return format will be a difference, computed in whatever base is specified, with as few digits as possible,
i.e., "0010" would be returned as "10", etc. We require 2 <= base <= 10.

The result is not defined if the minuend is less than the subtrahend!

For example,
std::string diff1 = subtract("130", "14", 10); // diff1 == "116"
std::string diff2 = subtract("101", "10", 2); // diff == "11"
subtract("30", "108", 10); // Do not do this!

@param minuend the term being subtracted from
@param subtrahend the value being subtracted
@param base the base being used

@return the difference, minuend-subtrahend in the base given
*/
std::string subtract(const std::string& minuend, std::string subtrahend, unsigned char base);


/**
This function determines whether two string representations of unsigned integers satisfy <= numerically

For example,
lessThanOrEqual("12", "108"); // true
lessThanOrEqual("100", "100"); // true
lessThanOrEqual("19", "6"); // false

@param first the first number
@param second the second number

@return whether first <= second as unsigned integer types
*/
bool lessThanOrEqual(const std::string& first, const std::string& second);


/**
 Additional function written besides the ones needed for the assignment. Given two string inputs of two different lengths, prepends the shorter string with 0's until both strings are the same length and have the same total number of characters
 
 For example,
 std::string num1 = "100", num2 =  "1";
 prepend (num1,num2);
 // now, num1 == "100", num2 == "001"
 
 @param num1 some string representation of an unsigned int that has a different length as num2
 @param num2 some string representation of an unsigned int that has a different length as num1
 */

void prepend( std::string & num1, std::string & num2);

/**
 Additional function written besides the ones needed for the assignment. Given an integer decimal number in string format, solves for the maximum power of two that is less than or equal to the decimal
 
 For example,
 int current_max_power = find_current_maxpower ("10"); // current_max_power ==  3
 int current_max_power = find_current_maxpower ("16"); // current_max_power ==  4
 int current_max_power = find_current_maxpower ("2"); // current_max_power ==  1
 
 @param decimal_string a string representation of an unsigned integer in base 10,  for which this function will calculate the maximum power of 2 in base 10 that will be less than or equal to it.
 
 @return an size_t representing an unsigned integer n, where 2^n  <= decimal_string
 */

size_t find_current_maxpower(const std::string & decimal_string);


#endif
