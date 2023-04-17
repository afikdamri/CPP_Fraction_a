/**
 * Test file
 */
#include "doctest.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "sources/Fraction.hpp"
#include "doctest.h"
using namespace ariel;

TEST_CASE("Test 1: Creating a Fraction with valid input")
{
    Fraction f1(1, 2);
    Fraction f2(-3, -5);
    Fraction f3(0, 1);
    Fraction f4(3, 4);
    Fraction f5(8, 12);
    Fraction f6(-7, 10);

    CHECK(f1.getNumerator() == 1);
    CHECK(f1.getDenominator() == 2);
    CHECK(f2.getNumerator() == -3);
    CHECK(f2.getDenominator() == -5);
    CHECK(f3.getNumerator() == 0);
    CHECK(f3.getDenominator() == 1);
    CHECK(f4.getNumerator() == 3);
    CHECK(f4.getDenominator() == 4);
    CHECK(f5.getNumerator() == 8);
    CHECK(f5.getDenominator() == 12);
    CHECK(f6.getNumerator() == -7);
    CHECK(f6.getDenominator() == 10);
}

TEST_CASE("Test 2: Creating a Fraction with invalid input")
{
    CHECK_THROWS(Fraction(1, 0));
    CHECK_THROWS(Fraction(-1, 0));
}

TEST_CASE("Test 3: Adding Fractions")
{
    Fraction f1(1, 2);
    Fraction f2(3, 4);

    CHECK((f1 + f2) == Fraction(5, 4));
    CHECK((f2 + f1) == Fraction(5, 4));
}

TEST_CASE("Test 4: Subtracting Fractions")
{
    Fraction f1(1, 2);
    Fraction f2(3, 4);

    CHECK((f2 - f1) == Fraction(1, 4));
    CHECK((f1 - f2) == Fraction(-1, 4));
}

TEST_CASE("Test 5: Multiplying Fractions")
{
    Fraction f1(1, 2);
    Fraction f2(3, 4);

    CHECK((f1 * f2) == Fraction(3, 8));
    CHECK((f2 * f1) == Fraction(3, 8));
}

TEST_CASE("Test 6: Dividing Fractions")
{
    Fraction f1(1, 2);
    Fraction f2(3, 4);

    CHECK((f1 / f2) == Fraction(2, 3));
    CHECK((f2 / f1) == Fraction(3, 2));
}

TEST_CASE("Test 7: Comparing two Fractions for equality")
{
    Fraction f1(1, 2);
    Fraction f2(2, 3);

    CHECK(f1 == f1);
    CHECK(f2 == f2);
    CHECK(f1 != f2);
}

TEST_CASE("Test 8: Comparing two Fractions with operators")
{
    Fraction f1(1, 2);
    Fraction f2(3, 4);
    Fraction f3(2, 4);
    Fraction f4(4, 6);

    CHECK(f1 < f2);
    CHECK(f2 > f1);
    CHECK(f1 <= f3);
    CHECK(f3 >= f1);
    CHECK(f3 < f4);
    CHECK(f4 > f3);
}

TEST_CASE("Test 9: Adding Fractions with for loop")
{
    Fraction f1(1, 2);
    Fraction f2(3, 4);
    Fraction result(0, 1);

    for (int i = 0; i < 10; ++i)
    {
        result = result + f1;
    }

    CHECK(result == Fraction(5, 1));
}

TEST_CASE("Test 10: Multiplying Fractions with for loop")
{
    Fraction f1(1, 2);
    Fraction f2(3, 4);
    Fraction result(1, 1);

    for (int i = 1; i <= 5; ++i)
    {
        result = result * f2;
    }

    CHECK(result == Fraction(243, 1024));
}

TEST_CASE("Test 11: Adding Fractions with negative numerator using for loop")
{
    Fraction f1(-1, 2);
    Fraction f2(-3, 4);
    Fraction result(0, 1);

    for (int i = 0; i < 10; ++i)
    {
        result = result + f1;
    }

    CHECK(result == Fraction(-5, 1));
}

TEST_CASE("Test 12: Multiplying Fractions with negative denominator using for loop")
{
    Fraction f1(1, -2);
    Fraction f2(3, -4);
    Fraction result(1, 1);

    for (int i = 1; i <= 5; ++i)
    {
        result = result * f2;
    }

    CHECK(result == Fraction(-243, 1024));
}

TEST_CASE("Test 13: Increment and Decrement operators")
{
    Fraction f1(1, 2);
    Fraction f2(-3, 4);

    // Postfix
    Fraction f3 = f1++;
    Fraction f4 = f2--;
    CHECK(f1 == Fraction(3, 2));
    CHECK(f3 == Fraction(1, 2));
    CHECK(f2 == Fraction(-7, 4));
    CHECK(f4 == Fraction(-3, 4));

    // Prefix
    Fraction f5 = ++f1;
    Fraction f6 = --f2;
    CHECK(f1 == Fraction(5, 2));
    CHECK(f5 == Fraction(5, 2));
    CHECK(f2 == Fraction(-11, 4));
    CHECK(f6 == Fraction(-11, 4));
}

TEST_CASE("Test 14: Comparison with integers")
{
    Fraction f1(1, 2);
    Fraction f2(4, 3);
    Fraction f3(1, 1);

    CHECK((f1 == f3) == false);
    CHECK((f1 < f3) == true);
    CHECK((f1 <= f3) == true);
    CHECK((f2 > f3) == true);
    CHECK((f2 >= f3) == true);
}

TEST_CASE("Test 15: Simplifying Fractions")
{
    Fraction f1(4, 6);
    Fraction f2(-8, 12);
    Fraction f3(3, 9);

    Fraction f4(2, 3);
    Fraction f5(-2, 3);
    Fraction f6(1, 3);

    CHECK(f1 == f4);
    CHECK(f2 == f5);
    CHECK(f3 == f6);
}
