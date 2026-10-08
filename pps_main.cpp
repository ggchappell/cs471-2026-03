// pps_main.cpp
// Glenn G. Chappell
// 2026-10-06
//
// For CS 471 Fall 2026
// Simple main program for prettyPrintSquare
// Requires pps.hpp

#include "pps.hpp"
// For prettyPrintSquare
#include <iostream>
using std::cout;
using std::cin;
#include <string>
using std::string;


// userPause
// Print given message and wait for user to press ENTER.
void userPause(const string & msg)
{
    std::cout.flush();
    cout << msg;
    while (std::cin.get() != '\n') ;
}


// Main program
// Demonstrate calling prettyPrintSquare.
int main()
{
    // Set up data
    int n = 11;  // Value to pass to prettyPrintSquare

    // Do output
    cout << "n = " << n << "\n";
    cout << "\n";
    cout << "Calling prettyPrintSquare:\n";
    prettyPrintSquare(n);

    // Wait for user
    cout << "\n";
    userPause("Press ENTER to quit ");
}

