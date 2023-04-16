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


TEST_CASE("Creating a Fraction with valid input") {
    Fraction f1(1, 2);
    Fraction f2(-3, -5);
    Fraction f3(0, 1);
    Fraction f4(3, 4);
    Fraction f5(8, 12);
    Fraction f6(-7, 10);

    CHECK(f1.getNumerator() == 1);
    CHECK(f1.getDenominator() == 2);
    CHECK(f2.getNumerator() == 3);
    CHECK(f2.getDenominator() == 5);
    CHECK(f3.getNumerator() == 0);
    CHECK(f3.getDenominator() == 1);
    CHECK(f4.getNumerator() == 3);
    CHECK(f4.getDenominator() == 4);
    CHECK(f5.getNumerator() == 2);
    CHECK(f5.getDenominator() == 3);
    CHECK(f6.getNumerator() == -7);
    CHECK(f6.getDenominator() == 10);
}

TEST_CASE("Creating a Fraction with invalid input") {
    CHECK_THROWS(Fraction(1, 0));
    CHECK_THROWS(Fraction(-1, 0));
}

TEST_CASE("Adding two Fractions") {
    Fraction f1(1, 2);
    Fraction f2(3, 4);

    CHECK((f1 + f2) == Fraction(5, 4));
    CHECK((f2 + f1) == Fraction(5, 4));
}

TEST_CASE("Subtracting two Fractions") {
    Fraction f1(1, 2);
    Fraction f2(3, 4);

    CHECK((f2 - f1) == Fraction(1, 4));
    CHECK((f1 - f2) == Fraction(-1, 4));
}

TEST_CASE("Multiplying two Fractions") {
    Fraction f1(1, 2);
    Fraction f2(3, 4);

    CHECK((f1 * f2) == Fraction(3, 8));
    CHECK((f2 * f1) == Fraction(3, 8));
}

TEST_CASE("Dividing two Fractions") {
    Fraction f1(1, 2);
    Fraction f2(3, 4);

    CHECK((f1 / f2) == Fraction(2, 3));
    CHECK((f2 / f1) == Fraction(4, 3));
}

TEST_CASE("Comparing two Fractions for equality") {
    Fraction f1(1, 2);
    Fraction f2(3, 4);
    Fraction f3(2, 4);
    Fraction f4(4, 6);

    CHECK(f1 == f1);
    CHECK(f2 == f2);
    CHECK(f1 != f2);
    CHECK(f1 == f3);
    CHECK(f3 == f4);
}

TEST_CASE("Comparing two Fractions with operators") {
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