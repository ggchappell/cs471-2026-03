// pps.hpp
// Glenn G. Chappell
// 2026-10-06
// Header for prettyPrintSquare
// There is no associated source file.

#ifndef FILE_PPS_HPP_INCLUDED
#define FILE_PPS_HPP_INCLUDED

#include <iostream>  // For std::cout
#include <string>    // For std::to_string
#include <cstdlib>   // For std::size_t


// prettyPrintSquare
// Takes an int and prints its square surrounded by box of asterisks,
// with a newline at the end of each line, to stanard output.
//
// For example, given 5, prints, with a newline after each line:
// ******
// * 25 *
// ******
inline
void prettyPrintSquare(int n)
{
    // Data
    auto nn = n*n;
    auto ss = std::to_string(nn);
    auto len = ss.size();

    // Print line 1
    for (std::size_t i = 0; i < len+4; ++i)
        std::cout << '*';
    std::cout << '\n';

    // Print line 2
    std::cout << "* " + ss + " *\n";

    // Print line 3
    for (std::size_t i = 0; i < len+4; ++i)
        std::cout << '*';
    std::cout << '\n';
}


#endif  //#ifndef FILE_PPS_HPP_INCLUDED

