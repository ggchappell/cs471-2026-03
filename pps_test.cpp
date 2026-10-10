// pps_test.cpp
// Glenn G. Chappell
// Started: 2024-10-04
// Updated: 2024-10-09
//
// For CS 471 Fall 2024
// Test suite for prettyPrintSquare and related code
// Uses doctest unit-testing framework
// Requires doctest.h, pps.hpp

// Includes for code to be tested
#include "pps.hpp"       // For prettyPrintSquare, related code
#include "pps.hpp"       // Double-inclusion check, for testing only

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
                             // doctest writes main for us
#include "doctest.h"         // For doctest framework

#include <string>
using std::string;
#include <sstream>
using std::ostringstream;


// class ComputeMock
// A compute class (derived from Compute): member func doint returns its
// parameter. For passing compute mock objects to prettyPrintSquare.
class ComputeMock : public Compute {
public:

    virtual ~ComputeMock() {}

    virtual int doint(int n) const
    { return n; }
};


// class FormatMock
// A format class (derived from Format): member func dostr returns its
// parameter. For passing format mock objects to prettyPrintSquare.
class FormatMock : public Format {
public:

    virtual ~FormatMock() {}

    virtual string dostr(const string & s) const
    { return s; }
};


TEST_CASE( "prettyPrintSquare default behavior works" )
{
    {
    ostringstream ostr;
    int arg = 5;
    string expected = "******\n* 25 *\n******\n";
    prettyPrintSquare(arg, ostr);
    string result = ostr.str();
    CHECK(result == expected);
    }

    {
    ostringstream ostr;
    int arg = 1234;
    string expected = "***********\n* 1522756 *\n***********\n";
    prettyPrintSquare(arg, ostr);
    string result = ostr.str();
    CHECK(result == expected);
    }
}


TEST_CASE( "Basic infrastructure of prettyPrintSquare works" )
{
    {
    ostringstream ostr;
    int arg = 6;
    string expected = "6";
    prettyPrintSquare(arg, ostr, ComputeMock(), FormatMock());
    string result = ostr.str();
    CHECK(result == expected);
    }
}


TEST_CASE( "Squaring works" )
{
    Square s;

    {
    int arg = 4;
    int expected = 16;
    auto result = s.doint(arg);
    CHECK(result == expected);
    }

    {
    int arg = -1;
    int expected = 1;
    auto result = s.doint(arg);
    CHECK(result == expected);
    }
}


TEST_CASE( "Squaring works for prettyPrintSquare in isolation" )
{
    {
    ostringstream ostr;
    int arg = 5;
    string expected = "25";
    prettyPrintSquare(arg, ostr, Square(), FormatMock());
    string result = ostr.str();
    CHECK(result == expected);
    }
}


TEST_CASE( "Box making works" )
{
    AsterBox b;

    {
    string ss = "xyz";
    string expected = "*******\n* xyz *\n*******\n";
    auto result = b.dostr(ss);
    CHECK(result == expected);
    }
}


TEST_CASE( "Box making works for prettyPrintSquare in isolation" )
{
    {
    ostringstream ostr;
    int arg = 5;
    string expected = "*****\n* 5 *\n*****\n";
    prettyPrintSquare(arg, ostr, ComputeMock());
    string result = ostr.str();
    CHECK(result == expected);
    }
}

