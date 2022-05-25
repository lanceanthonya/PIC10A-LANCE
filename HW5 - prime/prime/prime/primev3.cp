//
//  prime.cpp
//  Prime factor generator that accepts a range of integers, then calculates and prints all of the prime factors for the given integer
// Notes
/*
 - Used unsigned signed long long int (max size = (2^64) – 1 )
 - How to determine the prime factors of a given number "num" if I was a computer
    - The first divisior i is 2
    - First try dividing num by i
    - If num%i ==0, then i is
    - If num%i != 0, increase i by 1 until num%i == 0 again
    - if i
    - keep doing above until num ==1
*/
 //  Created by Lance Aquino on 1/31/22.
// Best working version

#include <iostream>
/*
using namespace std;

int main() {
    
    // Sets lower and upper bounds of numbers to factorize. Must be able to handle integer inputs as large as 10 billion
    unsigned long long int low_bound, up_bound;
    cout << "Enter a range of numbers to factorize. Enter lower bound and upper bound separated by a space: ";
    cin >> low_bound >> up_bound;
    
    // Starts a for loop that iterates each integer between the lower bound and upper bound
    for (unsigned long long int current_num = low_bound; current_num<=up_bound; ++current_num){ // iterator that starts with the lower bound and ends at the upper bound. Each iteration increases the current_num, or the current number being prime factored, by 1
        cout << current_num <<": ";
        unsigned long long int final_num = current_num; // final_num starts off as current_num, but gets modified in the next section
        
        // – The initial divisor is 2, since that is the smallest possible prime number you can divide by
        for (int divisor = 2; final_num>=1;){ // starting with a divisor of 2, this loop continues until final_num<=1
            if(final_num%divisor == 0 && current_num != 2){ // If the divisor divides evenly into final_num, prints the divisor. Does not execute if current_num is 2, which is a prime number but yields a remainder of 0 under this condition
                if (final_num != divisor){ // if final_num isn't the same as the divisor, the current divisor as well as an " x " is printed as the code cocntinues
                    final_num /= divisor;
                    cout << divisor << " x ";
                    
                }
                else { // when final_num becomes the same as the divisor, it means that this is the final divisor in the sequence, so the current for loop breaks and the next number in the defined range can be analyzed
                    cout << divisor << "\n";
                    break;
                }
            }
            else if (current_num == 1){
                cout <<"unit!\n";
                break;
            }
            else if (divisor>final_num/2 && final_num == current_num){ // if the number stored in final_num never changes while the divisor exceeds final_num/2, then current_num was a prime
                cout <<"prime! \n";
                break;
            }
            else { // increases the divisor if none of the previous conditions have been met yet
                ++divisor;
            }
        }
    }
    return 0;
}


*/
