////
////  tester.cpp
////  Linesweeper
////
////  Created by Lance Aquino on 3/5/22.
////
//
//#include <iostream>
//#include <vector>
//#include "Player.h"
//#include "LineOfMines.h"
//#include <string>
//#include <ctime>
//#include <cstdlib>
//
//using namespace std;
//int main() {
//
//    char continue_main_loop = 'y';
//    while (continue_main_loop == 'y'){ // determines if the main loop executes again
//        //starting routine
//        char continue_round_loop = 'y';
//        while (continue_round_loop == 'y'){ // determines if the loop for a given round executes again
//            // routine that executes for a given round
//            // prompt for user input that changes the value of continue_round loop to either continue or stop the current round
//        }
//        // end of round routine
//        // prompt for user input that changes the value of continue_main_loop to either play another game or to end the main loop
//    }
//    
//    
//    
//    return 0;
//}
/////**
//// lines for testing the Player Class
//// */
//////string user_name;
//////cout <<"Enter name: \n";
//////cin >> user_name;
//////Player P1 = Player(user_name);
//////
//////int new_score = 10;
//////if (P1.checkRecord(new_score)){
//////    cout<< "New score is " << new_score << "\n";
//////}
//////else{
//////    cout << "Score has not changed\n" ;
//////}
//////
//////
//////cout<< P1.getName() << "'s final score was: " << P1.getMaxScore();
//
////std::vector<std::string> locationDisplays  = std::vector<std::string>(_lineLength , "_____" );
////    /**
////     lines for testing the LineOfMines Class
////     */
////    srand(time(nullptr));
////
////    size_t line_len = 10;
////    size_t num_mines = 4;
////    LineOfMines G1 = LineOfMines(line_len,num_mines);
////
////    G1.display();
////
////    int input_pos;
////    while (true){
////        cout << "Input a number between 1 - 10: \n";
////        cin >> input_pos;
////
////        G1.makeSelection(input_pos);
////
////        G1.display();
////    }
////    cout << "Input a number between 1 - 10: \n";
////    cin >> input_pos;
////
////    G1.makeSelection(input_pos);
////
////    G1.display();
//
////    bool input_pos_has_mine = G1.containsMine(input_pos);
////    if (input_pos_has_mine){
////        G1.grandReveal();
////    }
