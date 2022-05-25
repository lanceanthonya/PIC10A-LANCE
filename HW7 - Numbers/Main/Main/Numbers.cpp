
#include "Numbers.h"
#include<stdexcept>
#include<string>


/**
If you are reading this, you may be puzzled as to why subtrahend is not passed as reference to const.
This is one of those few exceptions: we will need to make a copy of subtrahend anyway in order to modify
it in this function. It could actually be less efficient to pass by reference to const and then make a copy
inside the function. We just make a copy straightaway. Unless you really understand this deeply, do not
pass an object by value.
*/


std::string subtract(const std::string& minuend, std::string subtrahend, unsigned char base) {

	// ensure subtrahend has as many digits as minuend
	if (subtrahend.size() < minuend.size()) {
		subtrahend = std::string(minuend.size() - subtrahend.size(), '0') + subtrahend;
	}

	/* We first wish to modify each digit of subtrahend by turning it into its complement.
	The digit d should be converted into (base-1-d).
	*/
	for (auto &c : subtrahend) { // for each char in the subtrahend string
		// need to convert the char to digits, do the arithmetic, and go back to char!
		c = digitToChar( (base - 1) - charToDigit(c) );
	}

	//Subtraction can be done by addition, now. We first add 1 to the subtrahend.
	subtrahend = add(subtrahend, "1", base);

	// now, add the minuend and updated subtrahend
	std::string difference = add(minuend, subtrahend, base);

	/*
	The resulting number will always have a superfluous digit at index 0 that we do not want.
	In addition, we wish to move past all the zeros at the start.
	*/
	size_t zeroEnd = 1; // index to track where zeros end

	// size of the difference
	const size_t diff_sz = difference.size();

	// while index still within bounds (checked first) and there are still zeros
	while ((zeroEnd < diff_sz) && (difference[zeroEnd] == '0')) {
		++zeroEnd; // increase the index
	}

	if (zeroEnd == diff_sz) { // if zeroEnd is out of range then it was all 0's
		return "0";
	}

	return difference.substr(zeroEnd); // return the truncated number going from first nonzero to end of string
}


bool lessThanOrEqual(const std::string& first, const std::string& second) {
	if (first == second) { // if the two strings are equal, then they are equal!
		return true;
	}

	/* We need to look at their lengths: a longer number in proper format (no 0's at beginning)
	will always be larger than a number that is shorter */

	if (first.size() < second.size()) { // second longer
		return true; // so first < second
	}
	else if (second.size() < first.size()) { // first longer
		return false; // so first > second
	}
	else { // If the numbers have the same length, we can compare digit by digit because the chars 0-9 are ordered
		return first < second;
	}
}

unsigned char charToDigit(char c){
    unsigned char return_val = static_cast<unsigned char>(c) - '0';
    return return_val;
}

char digitToChar(unsigned char u){
    char return_val = static_cast<char>(u) + '0';
    return return_val;
}

void reverseString (std::string & input){
    std::string copy_of_word = input; //creates a copy of the word that the iterator can get the characters of the original string from
    int final_char_index = input.size() - 1; // gets the index of the final character in the string
    input = ""; //clears out the inputted string, so that the characters can be re-added in the opposite order
    for ( int current_char_index = final_char_index; current_char_index>=0; --current_char_index){ //iterates through the inputted string, starting with the final character and ending with the first character.
        input += copy_of_word[current_char_index]; //starting with the final character in the inputted string, concatenates the cleared out input string variable with the current character
    }
}

std::string add(const std::string& first, const std::string& second, unsigned char base){
    std::string num1 = first;
    std::string num2 = second;
    if (num1.size() !=  num2.size()){
        prepend (num1,num2);        
    }
    std::string result = "";
    int carry = 0;
    size_t final_char_index = num1.size()-1; // gets the index of the final character in the string
    for (size_t current_char_index = final_char_index; current_char_index>=0; --current_char_index){ //iterates through the inputted string, starting with the final character and ending with the first character.
        int current_num_of_num1 = static_cast<int>(charToDigit(num1[current_char_index])); //  converts the current numbers in the number strings into integers, for the following math operation
        int current_num_of_num2 = static_cast<int>(charToDigit(num2[current_char_index]));
        int total = carry + current_num_of_num1 + current_num_of_num2;
        char chardigit = digitToChar(total%base);
        result.push_back(chardigit);
        carry = total/base;
        if (current_char_index == 0) { // breaks if the current index is 0, to avoid undefined behavior that happens when it decrements
            break;
        }
    }
    if (carry != 0) {
        result+=digitToChar(carry);
    }
    reverseString(result);
    return result;
}



std::string twoPower(size_t pow){
    std::string result = "1";
    for (size_t current_pow = 0 ; current_pow < pow ; ++current_pow){
        result = add (result, result, 10 );
    }
    return result;
}


bool islessthanequalto(const std::string & first, const std::string & second){
    if  (first == second){
        return true;
    }
    std::string num1 = first;
    std::string num2 = second;
    if (num1.size() != num2.size()){
        prepend (num1,num2);
    }
    size_t final_index = num1.size() - 1;
    for (size_t current_index = 0; current_index <= final_index ; ++current_index) { // iterates through all numbers in both strings, left to right, until it finds a character where they differ
        int current_num1_digit = charToDigit(num1[current_index]);
        int current_num2_digit = charToDigit(num2[current_index]);
        if (current_num1_digit < current_num2_digit){ // if a digit at a given place in num1 is less than a digit at the same place in num2 from left to right, it means that num1 < num2
            return true;

        }
        else if (current_num1_digit > current_num2_digit){
            return false;
        }
    }
    return true;
}

void prepend( std::string & num1, std::string & num2){
    if (num1.size() <  num2.size() ){ //checks to see if the first inputted string is shorter than the other to see if it needs to prepend the first inputted string with zeroes
        while (num1.size() <num2.size()){ // continues to add "0" at the first position of the string until the strings have the same length
            num1.insert(0,"0");
        }
    }
    else if (num1.size() > num2.size() ){ // checks if the the second inputted string is shorter than the first
        while (num1.size() > num2.size()){
            num2.insert(0,"0");
        }
    }
}

int find_current_maxpower(std::string & decimal){
    int maxPower = 0;
    while ( islessthanequalto(twoPower(maxPower), decimal) ){ // Runs as long as 2^maxPower <= dec
        ++maxPower; // increments maxPower to check the next power
        if ( ! islessthanequalto(twoPower(maxPower), decimal) ){ //if the current maxPower goes above dec, it decrements once and the value produced is the true maxPower that is less than or equal to dec
            --maxPower;
            break;
        }
    }
    return maxPower;

}

std::string decimalToBinary(const std::string & decimal_int ){
    std::string dec = decimal_int;
    std::string binarystring = "";
    size_t maxPower = find_current_maxpower(dec);
    size_t current_pow = maxPower; // then, set maxPower = pow in the loop
    while ( current_pow >= 0){
        // if 2^pow <= dec, place a "1" at the front of the binary string then subtract 2^pow from dec and decrement pow. Doesn't execute if the current_pow ==0, which results in it decrementing and yielding undefined behavior if size_t goes below 0
        std::string current_two_powered = twoPower(current_pow);
        if ((lessThanOrEqual(current_two_powered, dec)) && (current_pow!=0)){
            dec = subtract(dec, current_two_powered, 10 ); //overwrites dec by subtracting the current power of 2 from it
            binarystring.insert(0,"1"); //adds a "1" to the leftmost position of the string representing a binary value
            --current_pow;
        }
        // if 2^pow > dec, place a "0" at the front of the binary string. then subtract 2^pow from dec and decrement pow.
        else if ((!lessThanOrEqual(current_two_powered, dec)) && (current_pow!=0)){
            binarystring.insert(0, "0");  //adds a "0" to the leftmost position of the string representing a binary value
            --current_pow;
        }
        // At the 2^0 position, these two else ifs break the loop to avoid undefined behavior that would occur if the above two control flows decrement current_pow = 0
        else if (current_pow == 0 && dec =="1"){ //  if the final number is a 1, binarystring is prepended with a 1 at the 2^0 position
            binarystring.insert(0,"1");
            break;
        }
        else if (current_pow == 0 && dec == "0"){ // prepends binarystring with a 0 at the 2^0 position 
            binarystring.insert(0,"0");
            break;
        }
        
    }
    reverseString(binarystring);
    return binarystring;
}

std::string binaryToDecimal(const std::string & binary_string){
    std::string binary_num = binary_string;
    reverseString(binary_num);
    const size_t binary_num_length = binary_num.size()-1; //the final index in the binary string
    const size_t base10 = 10;
    
    std::string decimal_num = "0";
    for (size_t current_two_power = 0; current_two_power <= binary_num_length; ++current_two_power){ // iterates through each power of 2 from 0 to the final place in the binary string, which represents the largest power of 2 in the string
        if (binary_num[current_two_power] == '0'){ // does not overwrite or add anything to decimal_num is the current number in the binary string is 0, indicating that this power of 2 does not contribute to the decimal value
        }
        else if (binary_num[current_two_power] == '1'){ // overwrites decimal_num by adding the current power of 2 to it, if there is a 1 at a given position in the binary string.
            std::string two_powered = twoPower(current_two_power);
            decimal_num = add(two_powered,decimal_num,base10);
        }
        
    }
    return decimal_num;
}
