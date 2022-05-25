
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
    //return_val will yield the unsigned char version of an ascii representation of some ascii number 0-9 by subtracting the ascii value of '0' from it. This results in a unsigned char, which can be converted into an int and used for calculations
    const unsigned char ascii_zero = '0';
    unsigned char return_val = static_cast<unsigned char>(c) - ascii_zero;
    
    return return_val;
}

char digitToChar(unsigned char u){
    //return_val will yield the char version of an ascii representation of some ascii number 0-9 by adding the ascii value of '0' to it. This results in a char representing the inputted the number that can be appended to strings
    const unsigned char ascii_zero = '0';
    char return_val = static_cast<char>(u) + ascii_zero;
    
    return return_val;
}

void reverseString (std::string & input){
    
    const std::string copy_of_word = input; //creates a copy of the word that the iterator can get the original characters of the un-edited string from
    
    const size_t final_char_index = input.size() - 1; // the index of the final character in the string
    
    for ( size_t current_char_index = 0; current_char_index <= final_char_index; ++ current_char_index){ //iterates through the index of each char in the string input, starting with the first character and ending with the final character in the string
        
        // final_char_index - current_char_index yields the index of the character at the "opposite position" in the original string that should replace the current character in the string input. If reading the string backwards, the index of the character at opposite_index would be the same as current_char_index
        size_t opposite_index =  final_char_index - current_char_index;
        char replacement_char = copy_of_word[opposite_index];
        
        input[current_char_index] = replacement_char; //character at the current position in the changing string input is replaced with replacement_char
    }
}

std::string add(const std::string& first, const std::string& second, unsigned char base){
    
    //copies of the inputted strings
    std::string num1 = first;
    std::string num2 = second;
    
    //checks to see if num1 and num2 are the same length, to determine if one of them needs to be prepended with zeroes until they have the same number of characters so that they add properly
    if (num1.size() !=  num2.size()){
        prepend (num1,num2);        
    }
    
    std::string result = "";  // an empty string that will be prepended with chars to form the sum of the strings first and second
        
    const size_t final_char_index = num1.size()-1; // gets the index of the final character in both strings string, since num1.size() == num2.size() after either one was prepended with 0's, if necessary
    
    int carry = 0; //carry represents how much of a previous place is carried over to the next place (for example: given 21 + 83 in base 10, 1 is carried over to the 100s place because of 20+80, while 1+3 yields no value to be carried over to the 10s place)

    for (size_t current_char_index = final_char_index; current_char_index>=0; --current_char_index){ //iterates through both num1 and num2, starting with characters in the smallest-value place (located at the index final_char_index) and decrementing until ending with the characters at the largest-value place (at the index 0)
        
        //  converts the current numbers in the number strings from a char to a digit to an integer, for the next calculation
        int current_num_of_num1 = static_cast<int>(charToDigit(num1[current_char_index]));
        int current_num_of_num2 = static_cast<int>(charToDigit(num2[current_char_index]));
        
        // determines the digit to add to the right side of result by calculating the total sum of the current numbers of num1 and num2 at that place as well as the carry value fom the previous place
        int total = carry + current_num_of_num1 + current_num_of_num2;
        char char_of_digit = digitToChar(total%base);
        result.push_back(char_of_digit); // appends the right side of result with the current chardigit.
        
        // Overwrites the value of carry to be carried over to the next place in the iteration. Since the value should be an int, only the
        carry = total/base;
        
        // breaks if the current index is 0, to avoid undefined behavior that happens when a size_t decrements past 0
        if (current_char_index == 0) {
            break;
        }
    }
    
    // appends the right side of the string with the carried over value, only if carry is not 0. Otherwise, this part is ignored
    if (carry != 0) {
        result.push_back(digitToChar(carry));
    }
    
    // since the string stored in result was created such that the smallest-value place is on the leftmost side of the string, while the largest-value place is on the right-most side of the string. Therefore, needs to be reversed in order to get the actual value for the sum of num1 and num2, where the smallest-place value is on the rightmost side of the string.
    
    reverseString(result);
    return result;
}


std::string twoPower(size_t pow){
    
    std::string result = "1"; // sets the starting result to 1, since 2^0 = 1.
    
    // iterates through each power of 2, starting from 1 and ending at the inputted pow. When pow == current_pow, result == 2^pow. Doesn't execute if pow == 0, since current_pow = 1 > pow = 0
    for (size_t current_pow = 1 ; current_pow <= pow ; ++current_pow){
        result = add (result, result, 10 ); // overwrites the result by adding the previous result to itself in base 10, or calculating the value of result * 2 in base 10 (mathematically, 2^n == 2^n-1 * 2^1 == 2^n-1 + 2^n-1)
    }
    return result; // returns a string representing 2^pow
}

void prepend( std::string & num1, std::string & num2){
    
//    const size_t first_position = 0; // represents the leftmost position of the string, which always has an index of 0
//
//    if (num1.size() <  num2.size() ){ //checks to see if the first inputted string is shorter than the other to see if it needs to prepend the first inputted string with zeroes
//        while (num1.size() < num2.size()){ // continues to add "0" at the leftmost/first position of num1 until the strings have the same length
//            num1.insert(first_position,"0");
//        }
//    }
//    else if (num1.size() > num2.size() ){ // checks if the the second inputted string is shorter than the first
//        while (num1.size() > num2.size()){ // continues to add "0" at the leftmost/first position of num2 until the strings have the same length
//            num2.insert(first_position,"0");
//        }
//    }
    std::string first = num1;
    std::string second = num2;
    size_t num1len = first.length();
    size_t num2len = second.length();

    int zeroes = num1len - num2len;
    if (zeroes< 0){
        num1.insert (0, -zeroes, '0');

    }
    if (zeroes >0){
        num2.insert (0, zeroes, '0');
    }

}

size_t find_current_maxpower(const std::string & decimal_string){
    size_t maxPower = 0;
    while ( lessThanOrEqual(twoPower(maxPower), decimal_string) ){ // Runs as long as 2^maxPower <= dec
        ++maxPower; // increments maxPower to check the next power
        if ( ! lessThanOrEqual(twoPower(maxPower), decimal_string) ){ //if the current maxPower goes above dec once, maxPower decrements once and the value produced should be the true max power of 2 that is less than or equal to decimal_string
            --maxPower;
            break;
        }
    }
    return maxPower;

}

std::string decimalToBinary(const std::string & decimal_string ){
//    //test
//    std::string stride = decimal_string;
//    reverseString(stride);
//    std::string dec = "0";
//    for (int index = 0; index <=decimal_string.length() -1 ; ++index){
//        const int binary_1 = 1;
//        if (charToDigit(stride[index])==binary_1){
//            const int dec_base = 10;
//            dec = add(dec, twoPower(index), dec_base);
//        }
//    }
//    return dec;
//
    std::string dec = decimal_string; // makes a copy of decimal_string that can change as the code progresses
    std::size_t maxPower = find_current_maxpower(dec); // calculates the greatest power of 2 that is less than or equal to decimal_string
    size_t current_pow = maxPower; // then, set maxPower = pow in the loop

    const size_t first_position = 0; // represents the leftmost position of the string, which always has an index of 0
    const size_t base10 = 10; // constant representing the input for base 10 in the subtract() function

    std::string binarystring = "";
    while ( current_pow >= 0){ // this loop iterates until current_pow reaches 0, where it will be broken by the last two else if statments

        std::string current_two_powered = twoPower(current_pow); // String of 2^current_pow, depending on the current iteration. Starts with current_pow == maxPower and ends with 2^0, when current_pow == 0

        // if 2^pow <= dec, places a "1" at the leftmost side of the binary string then subtracts 2^pow from dec and decrements pow. Doesn't execute if the current_pow ==0, which results in it decrementing and yielding undefined behavior if size_t goes below 0
        if ((lessThanOrEqual(current_two_powered, dec)) && (current_pow!=0)){
            dec = subtract(dec, current_two_powered, base10 ); //overwrites dec by subtracting the current power of 2 from it, in base 10
            binarystring.insert(first_position,"1"); //places a "1" to the leftmost position of the string representing a binary value
            --current_pow;
        }

        // if 2^pow > dec, place a "0" at the leftmost side of the binary string, then subtracts 2^pow from dec and decrement pow.
        else if ((!lessThanOrEqual(current_two_powered, dec)) && (current_pow!=0)){
            binarystring.insert(first_position, "0");  //places a "0" to the leftmost position of the string representing a binary value
            --current_pow;
        }

        // At the 2^0 position, these two else ifs break the loop to avoid undefined behavior that would occur if the above two control flows decrement current_pow = 0
        else if (current_pow == 0 && dec =="1"){ //  if the final number at the 2^0 position is a 1, binarystring is prepended with a 1
            binarystring.insert(first_position,"1");
            break;
        }
        else if (current_pow == 0 && dec == "0"){ //  if the final number at the 2^0 position is 0 prepends binarystring with a 0
            binarystring.insert(first_position,"0");
            break;
        }

    }
    reverseString(binarystring); //since the string is created by adding each binary digit to the left starting from the largest power of 2, the string needs to be reversed in order to yield the actual binary number
    return binarystring;
}

std::string binaryToDecimal(const std::string & binary_string){
    
    // The inputted binary number is reversed, so that the loop can work starting with the smallest power of 2 and ending with the largest power of 2
    std::string binary_num = binary_string;
    reverseString(binary_num);
    
    const size_t final_two_power = binary_num.size() - 1 ; // Gets the final index of the reversed binary string, which has the same value as the largest power of 2 in the binary number
    const size_t base10 = 10;
    
    std::string decimal_num = "0"; // This string is overwritten during the loop as each power of 2 is calculated and add() is used on this number and the current power of 2
    
    for (size_t current_two_power = 0; current_two_power <= final_two_power; ++current_two_power){ // iterates through each power of 2 from 0 to the final place in the binary string, which represents the largest power of 2 in the string

        if (binary_num[current_two_power] == '0'){/*empty*/} // does not overwrite or add anything to decimal_num if the current number in the binary string is 0, indicating that this power of 2 does not contribute to the decimal value. This is so that "two_powered" in the else if statement doesn't need to be calculated if there's a 0 at the position anyways
        
        else if (binary_num[current_two_power] == '1'){ // overwrites decimal_num by adding the current power of 2 to it, only if the binary number has a '1' at this position
            std::string two_powered = twoPower(current_two_power); // calculates 2^current_two_power
            decimal_num = add(two_powered , decimal_num , base10); // adds 2^current_two_power to the current decimal value, in base 10
        }
        
    }
    return decimal_num; // the final value of the decimal converted from binary
}
