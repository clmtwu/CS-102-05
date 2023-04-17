// Program Description: Calculating Average of Best Swim Dive Scores
// Details: 
/*
Write an application that, based on valid user input data, calculates 
the average of a group of diving score marks, where the lowest score 
in the group is dropped. 
The application should prompt and obtain user input at run-time for the 
following information:  5 diving scores.
Your program need use the following user-defined functions:
void getScore() - Asks the user for a diving score,
stores the validated user supplied data in a reference variable.
This function will be called by main once for each of five scores 
to be entered.
void calcAverage() - Calculates and displays the average of the 
four highest scores.
This function will be called just once by main and should be passed 
the five scores.
int findLowest() - Finds and returns the lowest of the five scores 
passed to it.
This function will be called by calcAverage(), 
which uses the function to determine which of the five scores to drop.
*/
// Software Development Environment: VSCode C++
// Solution File: clementwuLab3.cpp
// Date: 04/04/23
#include <iostream> //importing libraries with std
#include <iomanip>
using namespace std;

bool flag = true; //required global bool for loop

void getScore(int & ref) { //method to take in valid input
    int temporary; //placeholder int
    while(flag) { //loop
        cout << "Enter a diving score [0, 10]: ";
        cin >> temporary;
        if (!cin) { //checking if input is a number, if not clearing memory
        //and making user resubmit
            cin.clear();
            cout << "Error, Re-";
            cin.ignore (1000, '\n'); 
            continue;
        }
        if (temporary < 0 || temporary > 10) {
            //checking if number is within the bounds, if not 
            //making user resubmit
            cin.clear();
            cout << "Error, Re-";
            continue;
        }
        else { //if number passes, turning off loop
        //and submitting number to reference
            ref = temporary;
            flag = false;
        }
    }
    flag = true;
}

int findLowest(int lowest[]) { //method to return lowest number
    int temporary = lowest[0]; //setting arbitrary value to lowest
    //since we are checking it as we iterate through a loop
    for (int i = 0; i < 5; i++) {
    //checking if any of the indexes are lower than our arbitrary value
    //if so, replacing it with the lower value
        if (lowest[i] < temporary) {
            temporary = lowest[i];
        }
    }
    return temporary; //returning lowest value
}

void calcAverage(int input[]){ //method to calculate and print average
    int smallest = findLowest(input); //returning lowest input to subtract
    double sum; //temporary double
    for (int i = 0; i < 5; i++) { //loop to add every single element
        sum += input[i]; //adding all elements
    }
    cout << "After dropping the lowest score, " << smallest;
    //printing out lowest score
    cout << ", the diving average score is " << (double) (sum - smallest) / 4;
    //printing result with inline calculation of sum - smallest number and
    //its average of only 4 instead of 5
    cout << "." << endl; //ending
}

int main(){ //main function
    int scores[5]; //creation of index to manipulate,
    //much better than individual numbers
    for (int i = 0; i < 5; i++) { //iterating 
    //through array
        getScore(scores[i]); //passing index references
        //to populate
    }
    calcAverage(scores); //calculating scores
    return 0; //end of main
}
/* Program Output:
Enter a diving score [0, 10]: banana
Error, Re-Enter a diving score [0, 10]: apple
Error, Re-Enter a diving score [0, 10]: grape
Error, Re-Enter a diving score [0, 10]: why doesn't this program work
Error, Re-Enter a diving score [0, 10]: -1
Error, Re-Enter a diving score [0, 10]: 11
Error, Re-Enter a diving score [0, 10]: 5
Enter a diving score [0, 10]: 10
Enter a diving score [0, 10]: 7
Enter a diving score [0, 10]: 6
Enter a diving score [0, 10]: 8
After dropping the lowest score, 5, the diving average score is 7.75.
*/

