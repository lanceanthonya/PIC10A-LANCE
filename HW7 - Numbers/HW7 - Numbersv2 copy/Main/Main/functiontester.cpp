//////
//////  functiontester.cpp
//////  Main
//////
//////  Created by Lance Aquino on 2/19/22.
//////
//////
//#include<iostream>
//#include<vector>
//#include<string>
//#include "Numbers.h"
//
//using namespace std;
//int main(){
//
//    unsigned char char1 = 9;
//    unsigned char char2 = charToDigit('2');
//    unsigned char total = char1 + char2;
//    cout << digitToChar(total) ;
//
//
//    return 0;
//}
//////
////
/////*
//// string test_string ="i am your father";
//// reverseString (test_string);
//// cout<<test_string <<"\n";
////
//////
//////// code for the twoPower() function
//////
//////size_t inpower = 5;
//////cout<< "2 ^ " << inpower << " = "<< twoPower(inpower);
//////
//////*/
//////
////////prepend function
//////// string str1 = "9600";
//////// string str2 = "1000";
////////    prepend( str1, str2);
////////    cout<< str1 << "\n" <<str2;
//////// string sum141 = add (str1, str2, 10);
//////// cout << str1 << " + " << str2 << " = " << sum141;
//////
///////*
////// islessthanequalto()
//////
////// string num1 = "124";
////// string num2 = "123";
////// if (islessthanequalto(num1,num2)){
//////     cout << num1 << " <= " <<num2;
////// }
////// else{
//////     cout<<  num1 << " > " <<num2;
////// }
////// */
//////
//////// Find the largest power of 2, maxPower, so that 2^maxPower ≤ dec.
////////
////////    string dec = "15";
////////
////////    int finalval = find_current_maxpower(dec);
////////    cout << finalval;
//////
//////// OBJ: code for the function decimalToBinary() that accepts a string representation of a nonnegative integer in decimal and outputs its binary representation as a std::string;
////////    string dec = "4";
////////    // Starting with pow = maxPower, if 2^pow ≤ dec then place a ”1”, subtract 2pow from dec, and decrement pow. Otherwise, place a ”0” and decrement pow.
//////////    unsigned char base10 = 10;
////////    string binarystring = "";
////////    // first, find maxPower
////////    int maxPower = find_current_maxpower(dec);
////////    // then, set maxPower = pow in loop loop starto
////////    int current_pow = maxPower;
//////////    if (dec == "0"){
//////////        binarystring = "0";
//////////    }
//////////    else if (dec == "1"){
//////////        binarystring = "1";
//////////    }
//////////    if (current_pow == 0 && dec =="0"){
//////////        binarystring.insert(0,"0");
//////////    }
////////    while ( current_pow >= 0){
////////        // if 2^pow <= dec, then place a "1", then subtract 2^pow from dec and decrement pow.
////////        string current_two_powered = twoPower(current_pow);
////////        if (lessThanOrEqual(current_two_powered, dec)){
////////            dec = subtract(dec, current_two_powered, 10 );
////////            binarystring.insert(0,"1"); //adds a "1" to the leftmost position of the string representing a binary value
////////            --current_pow;
////////        }
////////        else if (!lessThanOrEqual(current_two_powered, dec)){
////////            binarystring.insert(0, "0");  //adds a "0" to the leftmost position of the string representing a binary value
////////            --current_pow;
////////        }
////////        else if (current_pow == 0 && dec =="1"){
////////            binarystring.insert(0,"1");
////////            break;
////////        }
////////    }
////////    reverseString(binarystring);
////////    cout<<binarystring;
//////
//////
//////// Stop the procedure after pow is 0.
//////
//////
//////// Testing decimalToBinary()
////////vector<string> fuckers = {"0","1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20","21","22","23","24",
////////        "25","26","27","28","29","30","31","32","33"
////////    };
////////    for (string i : fuckers){
////////        cout<< i <<" = ";
////////        cout<<decimalToBinary(i)<<"\n";
////////    }
////////0 = 0
////////1 = 1
////////2 = 10
////////3 = 11
////////4 = 100
////////5 = 101
////////6 = 110
////////7 = 111
////////8 = 1000
////////9 = 1001
////////10 = 1010
////////11 = 1011
////////12 = 1100
////////13 = 1101
////////14 = 1110
////////15 = 1111
////////16 = 10000
////////17 = 10001
////////18 = 10010
////////19 = 10011
////////20 = 10100
////////21 = 10101
////////22 = 10110
////////23 = 10111
////////24 = 11000
////////25 = 11001
////////26 = 11010
////////27 = 11011
////////28 = 11100
////////29 = 11101
////////30 = 11110
////////31 = 11111
////////32 = 100000
////////33 = 100001
//////
//////
////////Please enter two nonnegative binary integers: 1111111111111111111111111 1111111111111111111111100
////////Your first number in decimal is: 33554431
////////Your second number in decimal is: 33554428
////////Their sum in binary is: 11111111111111111111111011
////////Their sum in decimal is: 67108859
////////
////////Now enter two nonnegative decimal integers: 99999999999999999999 55555555555555555555
////////Your first number in binary is: 1010110101111000111010111100010110101100011000011111111111111111111
////////Your second number in binary is: 110000001011111100111110110110111010001100010111100011100011100011
////////Their sum in decimal is: 155555555555555555554
////////Their sum in binary is: 10000110111011000100010110011001101111101111011011100011100011100010
////////Program ended with exit code: 0
