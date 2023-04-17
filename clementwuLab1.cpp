// Program Description: Performs Arithmetic
// Details: 
/*
expression1:             my_id / 2
expression 2:            my_id % 2
expression 3:            2 + 3 + … + num_let
expression 4:            my_id + num_let
expression 5:            my_id * num_let
expression 6:            my_id += num_let 
expression 7:            my_id *= num_let;
expression 8:            my_id / (num_let + 1000)
expression 9:            sin(LEFT_MOST_DIGIT) */
// Software Development Environment: VSCode C++
// Solution File: clementwuLab1.cpp
// Date: 02/14/22
#include <iostream>
#include <string>
#include <iomanip>
#include <math.h>
using namespace std;

int main () {
 const int my_id = 0 + 4 + 9 + 4 + 8 + 1 + 0;
 //The sum of the numbers in your College login ID.
 const int num_let = 2;
 // The number of letters in your family (last) name.
 const int LEFT_MOST_DIGIT = 4;
 //defining leftmost digit that's not a 0

 double temporary = 0;
 //temporary variable
 double temporaryID = (double) my_id;
 //duplicating id in double to format

 //default prompt with last name, id, my_id, num_let with indent 
 cout << "My Last Name is: Wu" << endl;
 cout << "My Student Login ID is: 0494810" << endl;
 cout << "my_id is: " << my_id;
 cout << endl;
 cout << "num_let is: " << num_let;
 cout << "\n" << endl;

 //expression1:             my_id / 2
 cout << "Expression #1: " << my_id;
 cout << " / 2 = " << my_id / 2 ;
 cout << endl;

 //expression 2:            my_id % 2
 cout << "Expression #2: " << my_id;
 cout << " % 2 = " << my_id % 2 ;
 cout << endl;

 //expression 3:            2 + 3 + … + num_let
 //with for loop to add temporary values
 //temporary value cleared every time by setting it to 0
 //whenever it is used
 cout << "Expression #3: ";
 for (int i = 2; i <= my_id; i++) {
  temporary += i;
 }
 cout << "2 + 3 _ ... + num_let = " << temporary ;
 cout << endl;
 temporary = 0;

 //expression 4:            my_id + num_let
 //for expression 4-9, manipulating actual number to be
 //printed instead of being hardcoded
 cout << "Expression #4: " << my_id;
 cout << " + " << num_let;
 cout << " = " << my_id + num_let;
 cout << endl;

 //expression 5:            my_id * num_let
 cout << "Expression #5: " << my_id;
 cout << " * " << num_let;
 cout << " = " << my_id * num_let; 
 cout << endl; 

 //expression 6:            my_id += num_let 
 //setting temporary id to id+= let to print
 temporary = my_id + num_let;
 cout << "Expression #6: " << temporary;
 cout << " += " << num_let;
 cout << " = " << temporary; 
 cout << endl;

 //expression 7:            my_id *= num_let;
 //multiplying temporary by 7 to print
 temporary *= num_let;
 cout << "Expression #7: " << temporary;
 cout << " *= " << num_let;
 cout << " = " << temporary; 
 cout << endl;
 temporary = 0;

 //expression 8:            my_id / (num_let + 1000)
 //setting temporary to double to get precision to print
 temporary = temporaryID / (num_let + 1000);
 cout << "Expression #8: " << my_id;
 cout << " / " << num_let;
 cout << " + 1000 = "  << temporary; 
 cout << endl;

 //expression 9:            sin(LEFT_MOST_DIGIT) 
 //manually setting precision and calling leftmost directly
 cout << "Expression #9: sin(" << LEFT_MOST_DIGIT;
 cout << ") = " << setprecision(4) << sin(LEFT_MOST_DIGIT);
 cout << endl;

 return 0; //ending function
} //end of main

/* Program Output:
My Last Name is: Wu
My Student Login ID is: 0494810
my_id is: 26
num_let is: 2

Expression #1: 26 / 2 = 13
Expression #2: 26 % 2 = 0
Expression #3: 2 + 3 _ ... + num_let = 350
Expression #4: 26 + 2 = 28
Expression #5: 26 * 2 = 52
Expression #6: 28 += 2 = 28
Expression #7: 56 *= 2 = 56
Expression #8: 26 / 2 + 1000 = 0.0259481
Expression #9: sin(4) = -0.7568
*/

