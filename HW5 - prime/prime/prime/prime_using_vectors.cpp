//
//  main.cpp
//  prime
//Enter a range of numbers to factorize. Enter lower bound and upper bound separated by a space: [LOWER NUMBER ENTERED] [UPPER NUMBER ENTERED][EACH NUMBER]: [FACTORIZATION WITH x’s BETWEEN FACTORS OR “prime!” MESSAGE IF PRIME OR “unit!” IF THE NUMBER IS 1.
// Notes
/*
 Use unsigned signed long long int (max = (2^64) – 1
*/
 //  Created by Lance Aquino on 1/31/22.
//
/*
#include <iostream>
#include <vector>
using namespace std;


int main() {
    // Set lower and upper, the lower and upper bounds of numbers to factorize. Must be able to handle integer inputs as large as 10 billion

    unsigned long long int low_bound, up_bound;
    cout << "Enter a range of numbers to factorize. Enter lower bound and upper bound separated by a space: ";
    cin >> low_bound >> up_bound;
    
    // For each i from lower to upper... Create a list of each number between and including the lower and upper bound
    vector<long long int> numlist;
    unsigned long long int current_num = low_bound; //number currently being added to the number list
    while (current_num <= up_bound){ // starts with the lower bound, ends at the upper bound
        numlist.push_back(current_num);// adds the current number to the list, starting with low_bound
        current_num+=1; // moves on to the next number
    }
    
    for (size_t i = 0; i < numlist.size(); ++i) { // iterates through the
            cout << numlist.at(i) << "; ";
    }
     
    
    // – Set current to i and start with a divisor of divisor = 2. Until divisor exceeds i/2 or current equals 1...
    // If divisor divides evenly into current, set current = current/divisor and print divisor with an ‘x’ (or without an ‘x’ if current is 1).
    // * Otherwise, replace divisor by the smallest odd number bigger than divisor.
    // – If divisor has exceeded i/2, the number is prime.
    return 0;
}
*/
