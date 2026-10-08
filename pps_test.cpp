// pps_test.cpp
// Glenn G. Chappell
// 2026-10-07
//
// For CS 471 Fall 2026
// Test suite for prettyPrintSquare
// Uses doctest unit-testing framework
// Requires doctest.h, pps.hpp

// Includes for code to be tested
#include "pps.hpp"      // For prettyPrintSquare
#include "pps.hpp"      // Double-inclusion check, for testing only

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
                        // doctest writes main for us
#include "doctest.h"    // For doctest framework

#include <string>       // For std::string
#include <sstream>      // For std::ostringstream


TEST_CASE("prettyPrintSquare gives correct results")
{
    int arg = 12;
    std::string expected = "*******\n* 144 *\n*******\n";
    std::ostringstream oss;

    prettyPrintSquare(arg, oss);
    auto result = oss.str();

    CHECK(result == expected);
}

