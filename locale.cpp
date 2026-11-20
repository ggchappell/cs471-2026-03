// locale.cpp
// Glenn G. Chappell
// 2026-11-19
//
// For CS 471 Fall 2026
// Demo of C++ Locale

#include <iostream>
using std::cout;
#include <string>
using std::string;
using std::to_string;
#include <utility>
using std::pair;
#include <locale>
using std::locale;
using std::use_facet;
using std::numpunct;
#include <typeinfo>
using std::bad_cast;


// get_thousands_separator
// Given locale object. Returns a pair<char, bool>. The char is the
// thousands separator. The bool is true if the thousands separator was
// obtained from the locale, false if it is a default value (' ').
pair<char, bool> get_thousands_separator(const locale & loc)
{
    char thou_sep;     // Thousands separator
    bool from_locale;  // True if separator is from locale

    // Get thousands separator & store in thou_sep
    try
    {
        const auto & f = use_facet<numpunct<char>>(loc);
                         // Throws std::bad_cast if no facet
        thou_sep = f.thousands_sep();
        from_locale = true;
    }
    catch(bad_cast & e)
    {
        thou_sep = ' ';  // Our default thousands separator
        from_locale = false;
    }

    // Return results
    return { thou_sep, from_locale };
}



// int_with_separator
// Return string form of given integer with the given separator every 3
// digits.
// int_with_separator(-123456789, ",") returns "-123,456,789"s.
// int_with_separator(1234567, ".") returns "1.234.567"s.
// Requirements on Types:
//     IntType must be an integer type.
template <typename IntType>
string int_with_separator(IntType num,         // Integer to stringify
                          const string & sep)  // Separator
{
    const auto SPACING = 3;  // How many digits between separators
    auto result = to_string(num);
    auto pos = result.size();
    while (pos > SPACING + (num < 0))
    {
        pos -= SPACING;
        result.insert(pos, sep);
    }
    return result;
}


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
    cout << "Locale Demo\n";
    cout << "Number: " << num_to_print << "\n";
    cout << "\n";

    // Get thousands separator
    cout << "Attempting to get thousands separator from locale\n";
    locale loc("");  // Preferred locale
    auto sep_info = get_thousands_separator(loc);
    if (sep_info.second)
    {
        cout << "Success!\n";
    }
    else
    {
        cout << "Failure; default thousands separator used\n";
    }
    string sep(1, sep_info.first);
    cout << "Thousands separator: '" << sep << "'\n";
    cout << "\n";

    // Print our number
    cout << "Number with thousands separator: "
         << int_with_separator(num_to_print, sep) << "\n";
    cout << "\n";

    // Wait for user
    cout << "Press ENTER to quit ";
    userPause();
}

