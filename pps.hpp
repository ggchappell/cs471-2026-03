// pps.hpp
// Glenn G. Chappell
// Started: 2026-10-06
// Updated: 2026-10-07
//
// For CS 471 Fall 2026
// Header for prettyPrintSquare
// There is no associated source file.

#ifndef FILE_PPS_HPP_INCLUDED
#define FILE_PPS_HPP_INCLUDED

#include <iostream>  // For std::cout, std::ostream
#include <string>    // For std::string, std::to_string
#include <cstdlib>   // For std::size_t


// square
// Return square of parameter.
inline
int square(int n)
{
    return n*n;
}


// asterBox
// Return given string surrounded by a box of asterisks, with a newline
// at the end of each line.
//
// For example, given "abc", returns a string that prints as:
// *******
// * abc *
// *******
inline
std::string asterBox(const std::string & ss)
{
    // Set up
    auto len = ss.size();
    std::string result;

    // Line 1
    for (std::size_t i = 0; i < len+4; ++i)
        result.push_back('*');
    result.push_back('\n');

    // Line 2
    result += "* " + ss + " *\n";

    // Line 3
    for (std::size_t i = 0; i < len+4; ++i)
        result.push_back('*');
    result.push_back('\n');

    // Done; return our string
    return result;
}


// prettyPrintSquare
// Takes an int and prints its square surrounded by box of asterisks,
// with a newline at the end of each line, to stanard output.
//
// For example, given 5, prints, with a newline after each line:
// ******
// * 25 *
// ******
inline
void prettyPrintSquare(int n,
                       std::ostream & str=std::cout)
{
    auto nn = square(n);
    auto ss = std::to_string(nn);
    auto result = asterBox(ss);
    str << result;
}


#endif  //#ifndef FILE_PPS_HPP_INCLUDED

