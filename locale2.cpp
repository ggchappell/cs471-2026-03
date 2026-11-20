// locale2.cpp
// Glenn G. Chappell
// 2026-11-19
//
// For CS 471 Fall 2026
// Demo #2 of C++ Locale

#include <iostream>
using std::cout;
#include <locale>
using std::locale;


// userPause
// Wait for user to press ENTER: read all chars through first newline.
void userPause()
{
    std::cout.flush();
    while (std::cin.get() != '\n') ;
}


// Main program
// Print a number using the thousands separator, which is obtained from
// the locale, if possible.
int main()
{
    int num_to_print = -1234567890;  // Number to print with separator

    // Print intro message
    cout << "Locale Demo #2\n";
    cout << "Number: " << num_to_print << "\n";
    cout << "\n";

    // Get thousands separator
    cout << "Getting number format from locale\n";
    locale loc("");  // Preferred locale
    cout.imbue(loc);

    // Print our number
    cout << "Number using format from locale: "
         << num_to_print << "\n";
    cout << "\n";

    // Wait for user
    cout << "Press ENTER to quit ";
    userPause();
}

