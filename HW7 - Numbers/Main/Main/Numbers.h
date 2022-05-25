#ifndef _NUMBERS_
#define _NUMBERS_

#include<string>
#include<cstddef>

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
This function computes 2 to a given nonnegative integer power with the output as an std::string, in base 10

@param pow the power
@return 2 to that power
*/
std::string twoPower(size_t pow);

/**
 Given a string input, reverses the characters in the inputted string and returns nothing
 
 @param input a string of nums that needs to be reversed
 */
void reverseString (std::string & input);

/**
 Given two string input representations of numbers, determines if num1 is less than or equal to num2. Returns true if num1 <= num2, otherwise returns false
 
 @param num1 some string representation of an unsigned int
 @param num2 some string representation of an unsigned int
 
 @return bool for true if num1 <= num2, false if otherwise (when num1 > num2)
 */

bool islessthanequalto(const std::string & num1, const std::string & num2);

/**
 Given two string inputs of two different lengths, prepends the shorter string with 0's until both strings are the same length and have the same total number of characters
 
 @param num1 some string representation of an unsigned int that has a different length as num2
 @param num2 some string representation of an unsigned int that has a different length as num1
 */

void prepend( std::string & num1, std::string & num2);

/**
 Given an integer decimal number in string format, solves for the maximum power of two that is less than or equal to the decimal
 
 @param decimal a string representation of an unsigned integer that we want to find the maximum power of 2 that will be less than or equal to it.
 
 @return an int representing n, where 2^n <= decimal
 */

int find_current_maxpower(std::string & decimal);

/**
 Accepts a string representation of a unsigned integer in decimal and outputs its binary representation
 
 @param decimal_int a string representation of an unsigned integer in base 10, or decimal form
 
 @return a string representation of that same unsigned integer but in base 2, or binary format
 */
std::string decimalToBinary(const std::string & decimal_int );

/**
 Accepts a string representation of a binary number, and outputs the equivalent unsigned integer in decimal format
 
 @param binary_string a string representation of a binary number (base 2)
 
 @return a string representation of binary_string as an unsigned integer in base 10, or decimal form
 */
std::string binaryToDecimal(const std::string & binary_string);

#endif
