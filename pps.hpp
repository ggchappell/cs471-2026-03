// pps.hpp
// Glenn G. Chappell
// Started: 2026-10-06
// Updated: 2026-10-09
//
// For CS 471 Fall 2026
// Header for prettyPrintSquare
// There is no associated source file.

#ifndef FILE_PPS_HPP_INCLUDED
#define FILE_PPS_HPP_INCLUDED

#include <iostream>
// For std::cout, std::ostream
#include <string>
// For std::string, std::to_string


// class Compute
// Abstract base class for compute operations: member func doint takes
// int, does computation, returns resulting int.
class Compute {
public:

    virtual ~Compute() {}

    virtual int doint(int n) const = 0;
};


// class Square
// A compute class (derived from Compute): member func doint squares an
// int.
class Square : public Compute {
public:

    virtual ~Square() {}

    virtual int doint(int n) const
    {
        return n*n;
    }
};


// class Format
// Abstract base class for format operations: member func dostr takes
// string, does formatting, returns resulting string.
class Format {
public:

    virtual ~Format() {}

    virtual std::string dostr(const std::string & s) const = 0;
};


// class AsterBox
// A format class (derived from Format): member func dostr puts a box of
// asterisks around a string, with a newline at the end of each line.
class AsterBox : public Format {
public:

    virtual ~AsterBox() {}

    virtual std::string dostr(const std::string & ss) const
    {
        // Set up
        auto len = ss.size();
        std::string result;

        // Line 1
        result = std::string(len+4, '*') + "\n";

        // Line 2
        result += "* " + ss + " *\n";

        // Line 3
        result += std::string(len+4, '*') + "\n";

        // Done; return our string
        return result;
    }
};


// prettyPrintSquare
// Takes an int, does a compute operation, then a format operation on
// the string form of the result, then prints to the given stream.
// Default behavior is to square, surround with a box of asterisks, and
// print to std output.
//
// So, given 5, default behavior is to print the following to standard
// output, with a newline at the end of each line:
// ******
// * 25 *
// ******
inline
void prettyPrintSquare(int n,
                       std::ostream & str = std::cout,
                       const Compute & c = Square(),
                       const Format & f = AsterBox())
{
    auto nn = c.doint(n);
    auto ss = std::to_string(nn);
    auto result = f.dostr(ss);
    str << result;
}


#endif  //#ifndef FILE_PPS_HPP_INCLUDED

