/*
cpp code
*/
#include "Fraction.hpp"
using namespace std;

namespace ariel
{
    Fraction::Fraction(int num, int den) : numerator(num), denominator(den) {}

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

    Fraction operator-(const Fraction &f1, const Fraction &f2)
    {
        int num = f1.numerator * f2.denominator - f2.numerator * f1.denominator;
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
        for (int i = 1; i <= std::min(num, den); ++i)
        {
            if (num % i == 0 && den % i == 0)
            {
                gcd = i;
            }
        }
        return Fraction(num / gcd, den / gcd);
    }

    Fraction operator++(Fraction &f1, int)
    {
        Fraction result(f1);
        f1.numerator += f1.denominator;
        return result;
    }

    ostream &operator<<(ostream &os, const Fraction &f)
    {
        os << f.numerator << "/" << f.denominator;
        return os;
    }

    Fraction operator--(ariel::Fraction &f1, int)
    {
        ariel::Fraction result(f1);
        f1 = f1 - Fraction(1);
        return result;
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

    bool operator>(const Fraction &f1, const double &d)
    {
        double fractionValue = static_cast<double>(f1.getNumerator()) / f1.getDenominator();
        return fractionValue > d;
    }

    Fraction operator*(const double &d, const Fraction &f)
    {
        return Fraction(d) * f;
    }

    Fraction operator+(const Fraction &f, const double &d)
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

    Fraction Fraction::operator--(int)
    {
        Fraction result(*this);
        numerator -= denominator;
        reduce();
        return result;
    }

}
