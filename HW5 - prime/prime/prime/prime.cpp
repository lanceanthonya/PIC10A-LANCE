//
//  prime.cpp
//  Prime factor generator that accepts a range of integers as an input, then calculates and prints all of the prime factors for each of the given integers within that range, including the first and final inputted values
//  Created by Lance Aquino on 1/31/22.
//

#include <iostream>
using namespace std;

int main() {
    
    // Some constant values that are referred to within the loop. They aren't defined inside the loop so that they don't get created and destroyed each iteration of the loop
    const int unit = 1; // the number 1 is considered the "unit" and isn't considered a prime number. If this number is included in the specified range, the unique message "unit!" will print
    const int divisor_init = 2; //the initial divisor when analyzing each current_num is always 2, since it is the smallest possible prime number when prime factoring
    const int no_remainder = 0; // value that of final_num%divisor if the divisor still divides evenly into final_num
    const int smallest_prime =  2; // the smallest prime number is 2. This is important for some exceptions in the prime factorization process
    
    // Sets lower and upper bounds of numbers to prime factorize, from user input. Must be able to handle integer inputs as large as 10 billion, therefore an unsigned long long int type was used
    unsigned long long int low_bound, up_bound;
    cout << "Enter a range of numbers to factorize. Enter lower bound and upper bound separated by a space: ";
    cin >> low_bound >> up_bound;
    
    // Starts a for loop that iterates each integer between the lower bound and upper bound
    for (unsigned long long int current_num = low_bound; current_num<=up_bound; ++current_num){ // iterator that starts with the lower bound and ends at the upper bound. Each iteration increases the current_num (the current integer being prime factored) by 1
        cout << current_num <<": ";
        unsigned long long int final_num = current_num; // final_num starts off as current_num, but gets modified in the next section. This is done so that the current number being factored can be referred to while final_num is being modified separately
        
        //loop that iterates through the different possible divisors of current_num, and prints special messages in the cases that current_num == unit or if currrent_num is a prime number itself
        for (int divisor = divisor_init;;){ // Starting with a divisor of 2 (divisor_init), this loop continues until one of the several conditions with break statements are met. The divisor is not guaranteed to increment after every loop so that the same divisor can be used until it no longer goes into final_num.
            if(final_num%divisor == no_remainder && final_num != divisor && current_num != smallest_prime){ // If the divisor divides evenly  into final_num (has no remainder), it prints the divisor and an " x ". Specifies that the final_num cannot be the same as the divisor, so that the final prime factor in a sequence does not contain an extraneous " x ". Also does not execute if current_num is 2, which is a prime number but meets this condition.
                final_num /= divisor;
                cout << divisor << " x ";
            }
            else if (final_num==divisor && current_num!=smallest_prime) { // when final_num becomes the same as the divisor, it means that this divisor is the final prime factor in the sequence. Excludes 2, the smallest prime number
                cout << divisor << "\n";
                break;
            }
            else if (current_num == unit){ //  prints "unit!" if 1 is an integer included in the inputted sequence
                cout <<"unit!\n";
                break;
            }
            else if (final_num == current_num && (divisor > current_num/2)){ // if the number stored in final_num always remains the same as current_num and the divisor exceeds current_num/2, then current_num was already a prime and therefore can't be prime factored
                cout <<"prime! \n";
                break;
            }
            else{ // moves on to the next divisor, when the current divisor no longer meets any of the conditions
                ++ divisor;
            }
        }
    }
    return 0;
}


