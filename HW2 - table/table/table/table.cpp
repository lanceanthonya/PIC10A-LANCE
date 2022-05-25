//
//  table.cpp
/*
 - User inputs 3 data points (x and y), separated by a space
 - user inputs x-label i.e. Age [years]
 - user inputs y-label i.e. Alzheimers Prevalence [%]
 - user inputs a desired precision level for the values
 - creates a table with the values, with a top bar made of dashes (-) and a middle bar separating the values made of pipes (|)
 - calculates the line of best fit equation for the data as well as the correlation coefficient
*/
//Created by Lance Aquino on 1/21/22.
//

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;
int main() {

// user inputs 3 x- and y- data points

    double x1 = 0, y1 = 0;
    cout<<"Enter your first x- and y-values separated by a space: ";
    cin>>x1>>y1; //collecting user inputs separated by a space
    double x2 = 0, y2 = 0;
    cout<<"Enter your second x- and y-values separated by a space: ";
    cin>>x2>>y2;
    double x3 = 0, y3  = 0;
    cout<<"Enter your third x- and y-values separated by a space: ";
    cin>>x3>>y3;

// user inputs x and y labels as well as the precision level. a string is created for the top of the table, where the two different labels are separated by a pipe. The dashes at the top of the table are also generated based on the total length of the label

    cin.ignore(); // the last cin had a newline, which may interfere in the getline used in the next input lines
    string x_label,y_label;
    cout<<"Enter your x-label: ";
    getline(cin,x_label); //getline() is used instead of just cin because we need the entire user input in the line here, which may contain spaces that would cause issues if we used cin
    cout<<"Enter your y-label: ";
    getline(cin,y_label);
    int precision_level;
    cout<<"What level of precision would you like? ";
    cin>>precision_level;
    string labelstring = x_label + "|"+ y_label; // a string that prints the top label of the table, where the x and y labels are separated by a pipe character representing the middle of the table
    cout<<labelstring<<"\n";
    size_t table_width = labelstring.length(); // the width of the table is equal to the number of characters in total that make up the x and y labels, plus the pipe character
    cout << setfill ('-') << setw (table_width) <<""; //generates the dash (-) part of the table on one line
    cout <<"\n";

// prints the x and y values, separated by the middle line of pipes and underneath their respective labels
    
    size_t midline = x_label.length(); // the position of the center of the table is equal to the length of the x_label, whose end touches the middle of the table
    cout<<fixed<<setprecision(precision_level); //sets the precision of the inputted x and y values to the inputted precision_level for the rest of the code
    cout<< setfill (' ') <<setw(midline) << x1 <<"|" ;
    cout<< y1 << "\n";
    cout<< setfill (' ') <<setw(midline) << x2 <<"|" ;
    cout<< y2 << "\n";
    cout<< setfill (' ') <<setw(midline)<< x3 <<"|" ;
    cout<< y3 << "\n";

// calculating and printing the line of best fit equation
    
    int num_x_values = 3; //the number of x and y values
    int num_y_values = 3;
    double x_average = (x1 + x2 + x3)/num_x_values; //formula for the average value of the three inputted x- values, or x-bar
    double y_average = (y1 + y2 + y3)/num_y_values; //formula for average value of the three inputted y- values, or y-bar
    double best_fit_line= //calculating the slope "m" for the line of best fit
    (( x1 - x_average )*( y1 - y_average ) + ( x2 - x_average )*( y2 - y_average )+( x3 - x_average )*( y3 - y_average )) /
    (pow((x1-x_average),2) + pow((x2-x_average),2) + pow((x3-x_average),2));
    double best_fit_intercept = y_average - (best_fit_line*x_average); //calculating the y-intercept "b" for the line of best fit
    cout <<"The best fitting equation is: y = "<< best_fit_line<<"x + "<<best_fit_intercept<<"\n";
    
// calculating and printing the correlation coefficient
    
    double correlation_coefficient = //equation for calculating the correlation coefficient
    (( x1 - x_average )*( y1 - y_average ) + ( x2 - x_average )*( y2 - y_average )+( x3 - x_average )*( y3 - y_average )) /
    sqrt((pow((x1-x_average),2) + pow((x2-x_average),2) + pow((x3-x_average),2)) * (pow((y1-y_average),2) + pow((y2-y_average),2) + pow((y3-y_average),2)));
    cout<<"The correlation coefficient is: "<< correlation_coefficient;
    
    return 0;
}
