// Program Description:
// Software Development Environment: VSCode C++
// Solution File: clementwuLab4.cpp
// Date: 04/18/23
using namespace std;
#include <iostream> //importing libraries with std
#include <iomanip>
#include <math.h>

int finalsize = 12; //final size of the array
int initialcounter = 0; //starting index number
int DECIMALPLACES = 2; //number of decimal places

double scores[12]; //creation of index to manipulate,
bool flag = true; //flag for loop

void introductionMessage() { //intro formatted prompt
    cout << "YEARLY SALES - MIN / MAX" << endl;
    cout << "\nThis program will ask you to" 
            "\nenter twelve sales values, then it will"
            "\ndetermine the largest and smallest"
            "\nof the values you entered. \n" << endl;
}

//identical method from lab 3 but using double to store values
//instead of int
void setScore(double & ref) { //method to take in valid input
    double temporary; //placeholder int
    while(flag) { //loop
        cout << "Enter a value (>=0): ";
        cin >> temporary;
        if (!cin) { //checking if input is a number, if not clearing memory
        //and making user resubmit
            cin.clear();
            cin.ignore (1000, '\n'); 
            continue;
        }
        if (temporary < 0) {
            //checking if number is within the bounds, if not 
            //making user resubmit
            cin.clear();
            continue;
        }
        else { //if number passes, turning off loop
        //and submitting number to reference
            ref = temporary;
            cin.clear();
            flag = false;
        }
    }
    flag = true; //restarting loop when it reiterates
}

int decimalaccuracy(double result) { //method to calculate number of digits
//IN FRONT of decimal point for conversions
    int counter = 0;
    int digits = result;
    if (digits == 0) { //exception if 0, output must still release
    //0.xx, so return 0 and +2 constant later
        return 0;
    }
    while (digits != 0) { //while loop checking digit count over 0
        digits = digits / 10; //mod 10 to count
        counter++; //incrementing count for digit count
    }
    return counter; //returning result
} //end of output

void findMAX() { //method to print maximum score
    double largest = scores[0]; //setting largest number to 
    //random score
    for (int i = initialcounter; i < finalsize; i++) {
        //combing through each index to check if the number is bigger
        //if true, makes largest number the new number
        if (largest < scores [i]) {
            largest = scores [i];
        }
    }
    cout << "\nThe MAX monthly sales value $" << 
    //sets precision to the number of digits in front of the decimal point
    //and +2 for the precision after the decimal point
    setprecision(decimalaccuracy(largest) + DECIMALPLACES) 
    << largest << "." << endl;
    //prints result
}

void findMIN() { //method almost identical to above,
//but checks if the number is smaller instead of bigger
    double smallest = scores[0];
    for (int i = initialcounter; i < finalsize; i++) {
        if (smallest > scores [i]) {
            smallest = scores [i];
        }
    }
    cout << "The MIN monthly sales value $" << 
    setprecision(decimalaccuracy(smallest) + DECIMALPLACES) 
    << smallest << "." << endl;
}

int main(){ //main function
    introductionMessage(); //printing prompt
    for (int i = initialcounter; i < finalsize; i++) {
        setScore(scores[i]); //iterating score setter for each
        //of the 12 indexes
    }
    findMAX();
    //running method to find max
    findMIN();
    //running method to find min
    return 0; //end of main
}
/* Program Output:
YEARLY SALES - MIN / MAX

This program will ask you to
enter twelve sales values, then it will
determine the largest and smallest
of the values you entered.

Enter a value (>=0): please give me free money
Enter a value (>=0): i am very poor
Enter a value (>=0): -1
Enter a value (>=0): 123.10
Enter a value (>=0): 55.00
Enter a value (>=0): 150.75
Enter a value (>=0): 23.88
Enter a value (>=0): 66.10
Enter a value (>=0): 10.25
Enter a value (>=0): 4.77
Enter a value (>=0): 2.10
Enter a value (>=0): 45.99
Enter a value (>=0): 99.99
Enter a value (>=0): 11.00
Enter a value (>=0): 25.66

The MAX monthly sales value $150.75.
The MIN monthly sales value $2.1.
*/

