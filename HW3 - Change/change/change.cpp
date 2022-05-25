//
//  change.cpp
//  This program asks the user to input the true cost of an item (dollars and cents) and then computes the cost of said item in Canadian cash by rounding to the nearest nickel. It then collects the amount of each type of Canadian currency that the user paid with, records the total amount of dollars and cents the user paid, and finally calculates the amount of change the user is owed after their payment.
//  Created by Lance Aquino on 1/12/22.
//

#include <iostream>

using namespace std;

int main(){
    
    // user inputs for the true cost of the item, before it is rounded to the nearest nickel
    int inputted_dollars, inputted_cents; // declares variables that will store user inputs for the true cost's dollars & cents
    cout <<"Enter true cost.\n";
    cout<<"Give the dollars: ";
    cin >> inputted_dollars;
    cout<<"Now give the cents: ";
    cin >> inputted_cents;
    
    // rounds the number of inputted cents to the nearest nickel.
    int num_nickels_needed = ((static_cast<double>(inputted_cents)/5)+ 0.5); //how many nickels would hypothetically go into the cents cost, rounded to the nearest integer. This is how the cent cost was rounded to the "nearest nickel"
    int cents_per_nickel = 5;
    int rounded_cents = cents_per_nickel * num_nickels_needed; // calculates the new cents part of the cost, now rounded to the nearest nickel
    
    //conversion factor between dollars and cents, or how many cents are in a dollar. note that this conversion factor is used multiple times throughout the code
    int cents_in_a_dollar = 100;
    
    // finds the cost of the item in cash, with the cent cost now rounded to the nearest nickel
    double inputted_dollars_in_cents = inputted_dollars * cents_in_a_dollar; //converts inputted_dollars into its value in cents
    double rounded_cost_in_cents = (rounded_cents + inputted_dollars_in_cents); //total cost in cents, now rounded to the nearest nickel
    double rounded_cost = rounded_cost_in_cents/cents_in_a_dollar; // total cost of the item in dollars and cents decimal format, rounded to the nearest nickel
    cout<<"In cash, the item costs: $" << rounded_cost <<".\n";
    
    // user inputs each type of currency that they are paying with
    int num_toonies, num_loonies, num_fifties, num_quarters, num_dimes, num_nickels;
    cout<<"Enter payment details.\n";
    cout<<"Number of toonies: ";
    cin >> num_toonies;
    cout<<"Number of loonies: ";
    cin >> num_loonies;
    cout<<"Number of fifty cent pieces: ";
    cin >> num_fifties;
    cout<<"Number of quarters: ";
    cin >> num_quarters;
    cout<<"Number of dimes: ";
    cin >> num_dimes;
    cout<<"Number of nickels: ";
    cin >> num_nickels;
    
    // calculates how much the user paid, from their inputted currency amounts
    int toonies_in_cents = 200, // how many cents each type of currency is worth
        loonies_in_cents = 100,
        fifty_cents = 50,
        quarters_cents = 25,
        dimes_cents = 10,
        nickels_cents = 5;
    int amount_paid_in_cents = (toonies_in_cents * num_toonies) + (loonies_in_cents * num_loonies) + (fifty_cents * num_fifties) + (quarters_cents* num_quarters) + (dimes_cents * num_dimes) + (nickels_cents * num_nickels); //calculates the total value of the user's inputted currencies in cents
    int dollars_paid = amount_paid_in_cents / cents_in_a_dollar; // how many dollars were paid, excludes cents
    int dollars_paid_cents = dollars_paid * cents_in_a_dollar; // converts the number of dollars from previous line into cents for the next calculation
    int cents_paid = amount_paid_in_cents - dollars_paid_cents; // how many cents were paid
    cout << "You paid: " << dollars_paid << " dollar(s) and " <<cents_paid << " cent(s).\n";
    
    // calculates how much change the user is owed
    int total_change_in_cents = amount_paid_in_cents - rounded_cost_in_cents; // how much total change is owed, in cents
    int change_dollars =  total_change_in_cents/cents_in_a_dollar; // how many dollars of change are owed, excludes cents
    int change_cents = total_change_in_cents - (change_dollars  * cents_in_a_dollar); // calculates how many cents of change are owed, by subtracting the amount of dollars owed from the total change
    cout << "Your change due is: "<< change_dollars<< " dollar(s) and " <<change_cents << " cent(s). Have a nice day, eh!";
    
    return 0;
}
