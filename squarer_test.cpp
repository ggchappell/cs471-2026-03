// squarer_test.cpp
// Glenn G. Chappell
// 2026-09-30
//
// For CS 471 Fall 2026
// Test suite for class Squarer
// Uses doctest unit-testing framework
// Requires doctest.h, squarer.hpp

// Includes for code to be tested
#include "squarer.hpp"  // For class Squarer
#include "squarer.hpp"  // Double-inclusion check, for testing only

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
                        // doctest writes main for us
#include "doctest.h"    // For doctest framework


TEST_CASE("Squarer gives correct results for int")
{
    Squarer sq;    // Object that squares things
    int param;     // Parameter for sq
    int expected;  // Expected result from sq
    int result;    // Actual result from sq

    SUBCASE("Positive ints")
    {  // Because of this scope, INFO does not leak to later assertions
        param = 5;
        expected = 25;
        result = sq(param);
        INFO(param << " squared is " << expected);
        CHECK(result == expected);
    }

    SUBCASE("Negative ints")
    {
        param = -2;
        expected = 4;
        result = sq(param);
        INFO(param << " squared is " << expected);
        CHECK(result == expected);
    }

    SUBCASE("Zero int")
    {
        param = 0;
        expected = 0;
        result = sq(param);
        INFO(param << " squared is " << expected);
        CHECK(result == expected);
    }
}


TEST_CASE("Squarer gives correct results for double")
{
    Squarer sq;       // Object that squares things
    double param;     // Parameter for sq
    double expected;  // Expected result from sq
    double result;    // Actual result from sq

    SUBCASE("Positive doubles")
    {
        param = 1.1;
        expected = 1.21;
        result = sq(param);
        INFO(param << " squared is " << expected);
        CHECK(result == doctest::Approx(expected));
    }

    SUBCASE("Negative doubles")
    {
        param = -2.5;
        expected = 6.25;
        result = sq(param);
        INFO(param << " squared is " << expected);
        CHECK(result == doctest::Approx(expected));
    }

    SUBCASE("Zero double")
    {
        param = 0.0;
        expected = 0.0;
        result = sq(param);
        INFO(param << " squared is " << expected);
        CHECK(result == doctest::Approx(expected));
    }
}

