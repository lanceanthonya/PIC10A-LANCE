//
//  main.cpp
//  prime
//Enter a range of numbers to factorize. Enter lower bound and upper bound separated by a space: [LOWER NUMBER ENTERED] [UPPER NUMBER ENTERED][EACH NUMBER]: [FACTORIZATION WITH x’s BETWEEN FACTORS OR “prime!” MESSAGE IF PRIME OR “unit!” IF THE NUMBER IS 1.
// Notes
/*
 - Use unsigned signed long long int (max size = (2^64) – 1 )
 - How to determine the prime factors of a given number "num" if I was a computer
    - The first divisior i is 2
    - First try dividing num by i
    - If num%i ==0, then i is
    - If num%i != 0, increase i by 1 until num%i == 0 again
    - keep doing above until num ==1
 - Debugging notes
    - Current problem: How do we get it so that an " x " is not printed after the last number
        - When x is printed alongside the divisor when the divisor still goes into final_num, it results in an excess " x "
    - This is the current working build
*/
 //  Created by Lance Aquino on 1/31/22.
//
/*
#include <iostream>

using namespace std;


int main() {
    
    // Sets lower and upper bounds of numbers to factorize. Must be able to handle integer inputs as large as 10 billion
    unsigned long long int low_bound, up_bound;
    cout << "Enter a range of numbers to factorize. Enter lower bound and upper bound separated by a space: ";
    cin >> low_bound >> up_bound;
    

    
    // For each number from lower to upper
    for (unsigned long long int current_num = low_bound; current_num<=up_bound; ++current_num){ // iterator that starts with the lower bound and ends at the upper bound. Each iteration increases the current_num, or the current number being prime factored, by 1
        cout << current_num <<": ";
        unsigned long long int final_num = current_num; // final_num starts off as current_num, but gets modified in the next section
        // – Set current to i and start with a divisor of 2. Until divisor exceeds i/2 or current equals 1...
        for (int divisor = 2; final_num>=1;){ // starting with a divisor of 2, this loop continues until final_num<=1
            if(final_num%divisor == 0 && current_num != 2){ // If the divisor divides evenly into final_num, prints the divisor. Does not execute if current_num is 2, which is a prime number but yields a remainder of 0 under this condition
                final_num /= divisor;
                cout << divisor << " x ";
            }
            else if (divisor>final_num/2 && final_num == current_num){ // if the number stored in final_num never changes while the divisor exceeds final_num/2, then current_num was a prime
                cout <<"prime! \n";
                break;
            }
            
            else if (final_num == 1){
                cout <<"\n";
                break;
            }
            
            else { // increases the divisor if
                ++divisor;
            }
            
        }
    }
    // If divisor divides evenly into current, set current = current/divisor and print divisor with an ‘x’ (or without an ‘x’ if current is 1).
    // * Otherwise, replace divisor by the smallest odd number bigger than divisor.
    // – If divisor has exceeded i/2, the number is prime.

    return 0;
}
*/
