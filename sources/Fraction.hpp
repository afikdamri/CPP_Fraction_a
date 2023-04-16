#pragma once
#include <iostream>
#include <stdexcept>
#include <algorithm>

using namespace std;

namespace ariel
{
    class Fraction
    {
    private:
        int numerator;
        int denominator;

        void reduce()
        {
            int gcd = std::__gcd(numerator, denominator);
            numerator /= gcd;
            denominator /= gcd;
            if (denominator < 0)
            {
                numerator *= -1;
                denominator *= -1;
            }
        }

    public:
        Fraction(int num, int den = 1);
        Fraction();
        int getNumerator() const;
        int getDenominator() const;
        friend ostream &operator<<(std::ostream &os, const Fraction &f);

        friend Fraction operator+(const Fraction &f1, const Fraction &f2);
        friend Fraction operator+(const Fraction &f, const double &d);
        friend Fraction operator+(const double &d, const Fraction &f);

        friend Fraction operator-(const Fraction &f1, const Fraction &f2);
        friend Fraction operator-(const Fraction &f, const double &d);
        friend Fraction operator-(const double &d, const Fraction &f);

        friend Fraction operator/(const Fraction &f1, const Fraction &f2);
        /*friend Fraction operator/(const Fraction &f, const double &d);
        friend Fraction operator/(const double &d, const Fraction &f);*/

        friend Fraction operator*(const Fraction &f1, const Fraction &f2);
        friend Fraction operator*(const double &d, const Fraction &f);

        friend bool operator<(const Fraction &f1, const Fraction &f2);

        friend bool operator>(const Fraction &f1, const Fraction &f2);
        friend bool operator>(const Fraction& f1, const double& d);
 
        friend bool operator<=(const Fraction &f1, const Fraction &f2);
        friend bool operator>=(const Fraction &f1, const Fraction &f2);

        friend Fraction operator++(Fraction &f1, int);
        friend Fraction operator--(Fraction &f1, int);
        Fraction operator--(int);    

    };
}
