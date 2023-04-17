/*
cpp code
*/
#include "Fraction.hpp"
using namespace std;

namespace ariel
{
    Fraction::Fraction(int num, int den) : numerator(num), denominator(den)
    {
        if (den == 0)
        {
            throw std::invalid_argument("Denominator cannot be zero!");
        }
    }

    int Fraction::getNumerator() const
    {
        return numerator;
    }

    int Fraction::getDenominator() const
    {
        return denominator;
    }

    Fraction operator+(const Fraction &f1, const Fraction &f2)
    {
        int num = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
        int den = f1.denominator * f2.denominator;
        int gcd = 1;
        for (int i = 1; i <= std::min(num, den); ++i)
        {
            if (num % i == 0 && den % i == 0)
            {
                gcd = i;
            }
        }
        return Fraction(num / gcd, den / gcd);
    }

    Fraction operator+(const Fraction &f, const float &d)
    {
        int num = f.getNumerator() + (d * f.getDenominator());
        int den = f.getDenominator();
        int gcd = 1;
        for (int i = 1; i <= std::min(num, den); ++i)
        {
            if (num % i == 0 && den % i == 0)
            {
                gcd = i;
            }
        }
        return Fraction(num / gcd, den / gcd);
    }

    Fraction operator+(const float &d, const Fraction &f)
    {
        int num = f.getNumerator() + (d * f.getDenominator());
        int den = f.getDenominator();
        int gcd = 1;
        for (int i = 1; i <= std::min(num, den); ++i)
        {
            if (num % i == 0 && den % i == 0)
            {
                gcd = i;
            }
        }
        return Fraction(num / gcd, den / gcd);
    }

    Fraction operator-(const Fraction &f1, const Fraction &f2)
    {
        int num = f1.numerator * f2.denominator - f2.numerator * f1.denominator;
        int den = f1.denominator * f2.denominator;
        int abs_num = abs(num);
        int abs_den = abs(den);
        int gcd = 1;
        for (int i = 1; i <= std::min(abs_num, abs_den); ++i)
        {
            if (abs_num % i == 0 && abs_den % i == 0)
            {
                gcd = i;
            }
        }
        if (num < 0 && den < 0)
        {
            num = -num;
            den = -den;
        }
        num /= gcd;
        den /= gcd;
        return Fraction(num, den);
    }

    Fraction operator-(const Fraction &f, const float &d)
    {
        float numerator = f.numerator - (f.denominator * d);
        return Fraction(numerator, f.denominator);
    }

    Fraction operator-(const float &d, const Fraction &f)
    {
        float numerator = f.numerator - (f.denominator * d);
        return Fraction(numerator, f.denominator);
    }

    Fraction operator/(const Fraction &f1, const Fraction &f2)
    {
        int num = f1.numerator * f2.denominator;
        int den = f1.denominator * f2.numerator;
        int gcd = 1;
        for (int i = 1; i <= std::min(num, den); ++i)
        {
            if (num % i == 0 && den % i == 0)
            {
                gcd = i;
            }
        }
        return Fraction(num / gcd, den / gcd);
    }

    Fraction operator*(const Fraction &f1, const Fraction &f2)
    {
        int num = f1.numerator * f2.numerator;
        int den = f1.denominator * f2.denominator;
        int gcd = 1;
        for (int i = 1; i <= std::min(std::abs(num), std::abs(den)); ++i){
            if (num % i == 0 && den % i == 0){
                gcd = i;
            }
        }
        if (num < 0 && den < 0){
            num = std::abs(num);
            den = std::abs(den);
        }
        else if (den < 0){
            num *= -1;
            den = std::abs(den);
        }
        return Fraction(num / gcd, den / gcd);
    }

    ostream &operator<<(ostream &os, const Fraction &f)
    {
        os << f.numerator << "/" << f.denominator;
        return os;
    }

    bool operator<=(const Fraction &f1, const Fraction &f2)
    {
        return (f1.numerator * f2.denominator) <= (f2.numerator * f1.denominator);
    }

    bool operator>=(const Fraction &f1, const Fraction &f2)
    {
        return !(f1 < f2);
    }

    bool operator<(const Fraction &f1, const Fraction &f2)
    {
        int commonDenominator = f1.denominator * f2.denominator;
        int numerator1 = f1.numerator * f2.denominator;
        int numerator2 = f2.numerator * f1.denominator;

        return numerator1 < numerator2;
    }

    bool operator>(const Fraction &f1, const Fraction &f2)
    {
        return f1.numerator * f2.denominator > f2.numerator * f1.denominator;
    }

    bool operator>(const Fraction &f1, const float &d)
    {
        float fractionValue = static_cast<float>(f1.getNumerator()) / f1.getDenominator();
        return fractionValue > d;
    }

    Fraction operator*(const float &d, const Fraction &f)
    {
        float num = f.numerator * d;
        return Fraction(num, f.denominator);
    }

    // Prefix
    Fraction &Fraction::operator--()
    {
        numerator -= denominator;
        return *this;
    }

    // Postfix
    Fraction Fraction::operator--(int)
    {
        Fraction tmp(*this);
        --(*this);
        return tmp;
    }

    // Prefix
    Fraction &Fraction::operator++()
    {
        numerator += denominator;
        return *this;
    }

    // Postfix
    Fraction Fraction::operator++(int)
    {
        Fraction tmp(*this);
        ++(*this);
        return tmp;
    }

    bool operator==(const Fraction &f1, const Fraction &f2)
    {
        int gcd1 = __gcd(f1.numerator, f1.denominator);
        int gcd2 = __gcd(f2.numerator, f2.denominator);

        int num1 = f1.numerator / gcd1;
        int den1 = f1.denominator / gcd1;
        int num2 = f2.numerator / gcd2;
        int den2 = f2.denominator / gcd2;
        return (num1 == num2) && (den1 == den2);
    }
}
