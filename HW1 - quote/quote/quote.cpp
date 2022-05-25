//
//  quote.cpp
//  Simply prints text based on the prompt given by HW1
//  Created by Lance Aquino on 1/9/22.
//

#include <iostream>

using namespace std; // specifies that we're working within the standard namespace

int main() {
    cout << "Hello, world! My name is Lance.\n\n" //first paragraph in the prompt displayed. two newlines at the end of each paragraph are used to create blank space between paragraphs
        << "One of my favorite quotes is:\n\n" //second paragraph is displayed
        << "\"Hunger is the best spice.\" ~Jet Black from Cowboy Bebop\n\n" // third paragraph is displayed
        << "I like this because I agree that being hungry makes me enjoy food a lot more than when I'm not hungry."; //final paragraph is displayed

    return 0; //terminates the program
}
