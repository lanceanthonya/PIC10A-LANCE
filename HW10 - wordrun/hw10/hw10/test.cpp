////
////  fuckeronispalace.cpp
////  hw10
////
////  Created by Lance Aquino on 3/12/22.
////
//
//#include "WordRun.h"
//#include <iostream>
//#include <fstream>
//#include <string>
//#include <set>
//#include <cstdlib>
//#include <ctime>
//
//using namespace std;
//
//int main(){
//    srand(time(nullptr));
//    
//    cout<<wrgame.randword(); //remember to remove randword() before the final product
//
//    WordRun wrgame = WordRun();
//    cout << "Try to guess a 4-letter word. Letters in their rightful place get a ’*’. Letters of the word not in their place get a ’ ’. Otherwise, a ’-’ is displayed.\n";
//    string word_guess;
//    while (! wrgame.hasWon()){
//        getline(cin, word_guess);
//        wrgame.guess(word_guess);
//        cout << '\n';
//    }
//    cout << "You won and responded in "<< wrgame.getGuesses()<< " guesses, with a time of "<< wrgame.getTime() << " s, earning a score of " << wrgame.getScore() << "." ;
////    string end_timer = "n";
////    while (end_timer == "n"){
////        cout<<"end timer? ";
////        cin >> end_timer;
////    }
////    time_t time_fin = time(nullptr);
////
////    time_t duration = time_fin - time_init;
//    
////    cout << "You took" << to_string(static_cast<int>(duration)) << "seconds and" <<;
//    
//    // writing the guess function
//    //1st, check to see if the word is wrong size (input.size() != chosen.size())
//    //2nd see if it's a valid word
//    // look through the set
//    //3rd, hint 
//
//    return 0;
//}
//
////    ifstream wrdoth("/Users/lanceaquino/Desktop/PIC10A/HW10 - wordrun/hw10/hw10/word4.txt"); // change to just "word4.txt" when testing on vs code
////    string flword;
////    set<string> flwordset;
////    if (!wrdoth) {
////        cout << "Unable to open file\n";
////        exit(1); // terminate with error
////    }
////
////    else{
////        while (wrdoth >> flword){
////            flwordset.insert(flword);
//////            cout << " "<< flword;
////        }
////    }
////    wrdoth.close();
////    cout << flwordset.size(); // all words read into a set with 500 words
////    auto first_word = flwordset.begin(); // creates a pointer to the first word of the set
////    auto last_word = -- flwordset.end(); //creates a pointer to the final word of the set
////    auto first_word_plus_one = first_word ++;
//    
////    cout << "\n"<< *first_word;
////    cout << "\n" <<*first_word_plus_one;
////    cout << "\n" << *last_word << "\n";
//    
//    //randomly generate a word
//    
////    int times_to_randomly_iterate_thru_set = rand()%flwordset.size(); // generates a random number corresponding to how many times the while loop will go through the set until it stops. The word found when the number of times to iterate through the set is 0
////    auto iterator = flwordset.end(); // corresponds to a pointer pointing to the final word in the set. The while loop moves the pointer backwards until the times_to_randomly_iterate_thru_set is finished.
////
////    while (times_to_randomly_iterate_thru_set  > 0){
////        --times_to_randomly_iterate_thru_set;
////        --iterator;
////    }
////    cout<< *iterator;
////
////
