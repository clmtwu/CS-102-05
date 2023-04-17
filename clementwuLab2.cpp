// Program Description: Calculates carpooling prices
// Details: 
/*
Calculate the user's daily cost of driving their own car in a given day. 
Calculate carpool cost options of carpooling for one, two, three or four people.
Use parenthesis if needed to ensure your total calculation associativity 
and order of precedence produces a correct result.
Format  your monetary result to 2 decimal places of accuracy. 
Format to align decimal points in the same column for the output carpool options.
Use a space around all binary operators. 
Be sure that your output is well organized. 
Provide console output comments to organize your result displays. 
Define and use named constants in lieu of literal values.
 Where appropriate, use these named constants in your program solution. 
*/
// Software Development Environment: VSCode C++
// Solution File: clementwuLab2.cpp
// Date: 02/28/22
#include <iostream>
#include <string>
#include <iomanip>
#include <math.h>
using namespace std;
//including libraries and using std

int output(double result) { //method to calculate number of digits
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

int main () { //main executable
    double gasinput;
    double milesPerGallon;
    double milesDriven;
    double parkingFees;
    double tollCount;
    double cost;
    //srtandard cin variables for input

    int DECIMALPLACES = 2;
    //number of decimal places

    double resultTwo;
    double resultThree;
    double resultFour;
    //result vaeriables for calculation

    bool flag = true; //flag for input checking

    //from lines 67 - each "chunk" of code repeats the same code:
    //1. prompt for input,
    //2. checking if input is indeed a number:
    // - if not, clearing memory and starting over
    //3. checking if input is above 0
    // - if so, ending loop
    //4. else statement starts over the loop from the top with error prompt
    cout << "Enter cost per gallon of gas (in dollars.cents): ";
    while(flag) {
       cin >> gasinput;
       if (!cin) {
        cin.clear();
        cout << "Enter a valid number for cost per gallon of gas (in dollars.cents): ";
        cin.ignore( 1000, '\n' ); 
        continue;
       }
       else {
            if (gasinput > 0) {
                    flag = false;
                }
            else {
                cin.clear();
                cin.ignore( 1000, '\n' ); 
                cout << "Error - Please enter a non-negative number. Enter cost per gallon of gas (in dollars.cents): ";
            }
       }
    }

    
    flag = true;
    cout << "Enter average miles per gallon: ";
    while (flag) {
        cin >> milesPerGallon;
        if (!cin) {
            cin.clear();
            cout << "Enter a valid number for average miles per gallon:";
            cin.ignore( 1000, '\n' ); 
            continue;
        }
        else {
            if (milesPerGallon > 0) {
                flag = false;
            }
            else {
                cin.clear();
                cin.ignore( 1000, '\n' ); 
                cout << "Error - Please enter a non-negative number. Enter average miles per gallon: ";
            }
        }
    }

    cout << "Enter miles driven per day: ";
    flag = true;
    while (flag) {
         cin >> milesDriven;
        if (!cin) {
            cin.clear();
            cout << "Enter a valid number for miles driven per day: ";
            cin.ignore( 1000, '\n' ); 
            continue;
        }
        else {
            if (milesDriven >= 0) {
                flag = false;
            }
            else {
                cin.clear();
                cin.ignore( 1000, '\n' ); 
                cout << "Error - Please enter a non-negative number. Enter miles driven per day: ";
            }
        }
    }

    cout << "Enter parking fees per day (in dollars): ";
    flag = true;
    while (flag) {
         cin >> parkingFees;
        if (!cin) {
            cin.clear();
            cout << "Enter a valid number for parking fees per day (in dollars): ";
            cin.ignore( 1000, '\n' ); 
            continue;
        }
        else {
            if (parkingFees >= 0) {
                flag = false;
            }
            else {
                cin.clear();
                cin.ignore( 1000, '\n' ); 
                cout << "Error - Please enter a non-negative number. Enter parking fees per day (in dollars): ";
            }
        }
    }

    cout << "Enter tolls per day (in dollars): ";
    flag = true;
    while (flag) {
         cin >> tollCount;
        if (!cin) {
            cin.clear();
            cout << "Enter a valid number for tolls per day (in dollars): ";
            cin.ignore( 1000, '\n' ); 
            continue;
        }
        else {
            if (tollCount >= 0) {
                flag = false;
            }
            else {
                cin.clear();
                cin.ignore( 1000, '\n' ); 
                cout << "Error - Please enter a non-negative number. Enter tolls per day (in dollars): ";
            }
        }
    }

    //after verifying input, calculating the correct price
    cost = ((milesDriven / milesPerGallon) * gasinput) + parkingFees + tollCount;

    //calculating each result with the number of people: 2, 3, and 4
    resultTwo = cost / 2;
    resultThree = cost / 3;
    resultFour = cost / 4;

    //driving cost declaration with precisionsetting, +2 for decimal
    cout << "Your daily driving cost is: " << setprecision(output(cost) + 2) << cost;
    cout << endl;

    //printing calculations with decimal places
    cout << "\nCarpool Options:" << endl;
    cout << "1 person: " << setprecision(output(cost) + DECIMALPLACES) << cost;
    cout << endl;
    cout << "2 people: " << setprecision(output(resultTwo) + DECIMALPLACES) << resultTwo;
    cout << endl;
    cout << "3 people: " << setprecision(output(resultThree) + DECIMALPLACES) << resultThree;
    cout << endl;
    cout << "4 people: " << setprecision(output(resultFour) + DECIMALPLACES) << resultFour;
    cout << endl;
    return 0; //ending function
} //end of main

//Printing Output
/* 
Enter cost per gallon of gas (in dollars.cents): 4.5
Enter average miles per gallon: 23
Enter miles driven per day: 10
Enter parking fees per day (in dollars): 5
Enter tolls per day (in dollars): 7
Your daily driving cost is: 13.96

Carpool Options:
1 person: 13.96
2 people: 6.98
3 people: 4.65
4 people: 3.49
*/

