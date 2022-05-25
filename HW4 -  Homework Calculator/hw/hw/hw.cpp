//
//  hw.cpp
//  This program calculates and prints a student's score, based on their top inputted scores. The user inputs a number of scores n to take into account, and the best n scores out of their total number of homework assignments are used for the student's score calculation. The program  then determines a final message to print based on a determined score threshold.
//
//  Created by Lance Aquino on 1/29/22.
//

#include <iostream>
#include <string>
#include <iomanip>
#include "HomeworkList.h"

using namespace std;

int main(){
    
    // Student name is inputted. Spaces are allowed because of the use of getline
    
    string StudentName;
    cout <<"Enter student's name: ";
    getline(cin,StudentName);
    
    // Loop that accepts scores separated by a space until user selects "n" meaning that they have no more scores to provide. If they input y, the loop re-iterates and the prompt in input  another score is given
    
    HomeworkList hwlist; //creates a HomeworkList class item named hwlist
    string yesorno = "y";
    while (yesorno == "y"){ //continues to accept inputs for score and max possible score, as long as the value of yesorno is "y"
        int score = 0 , maxPossible = 0;
        cout<< "Enter score and max as two values: ";
        cin>>score>>maxPossible; // accepts an input for score and the maximum possible score as ints, separated by a whitespace
        hwlist.addScore(score,maxPossible); //appends hwlist with the inputted score & maximum
        cout<< "More scores? y/n: ";
        cin>> yesorno; // if user writes "y", the loop re-iterates. any other value, including "n" terminates the loop
    }
    
    //  User inputs a number topNumber for how many of the best scores from hwlist will be taken into account in the final percent score calculation. Precision for this percentage is set to 2 decimal places
    
    size_t topNumber;
    cout<<"How many scores should be used in computing the HW grade? ";
    cin >>topNumber;
    double calculated_score =  hwlist.percentageFromBest(topNumber); //the student's grade in % based on their topNumber best scores to be considered
    int precision_level = 2; // output precision for student's grade is set to two decimal places, i.e. 99.99, 10.11, etc...
    cout<<fixed<<setprecision(precision_level);
    size_t num_of_hws = hwlist.numberOfHWs(); // number of homework scores inputted by the user
    cout<< "The homework grade for " << StudentName << " based on the best " <<topNumber <<" homework scores out of " << num_of_hws <<" is " <<calculated_score<<"%.\n";
    
    // Determining the appropriate message to print, based on the student's calculated percentage based on their top scores
    
    if (95 <= calculated_score){ // prints the message for if a score is greater than or equal to 95
        cout << "This is excellent.";
    }
    else if ((80 <= calculated_score)&&(calculated_score<95)){ // prints the message for if the score is greater than/equal to 80 and less than 95
        cout << "This is good.";
    }
    else if ((70 <= calculated_score)&&(calculated_score<80)){ // prints the message for if the score is greater than/equal to 70 and less than 80
        cout << "This is decent.";
    }
    else if (calculated_score<70){ // prints the message for if the score is less than 70
        cout << "This is poor.";
    }
    return 0;
}
