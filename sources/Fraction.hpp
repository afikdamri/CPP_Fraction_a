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
        Fraction(int num, int den);
        Fraction(){numerator = 0; denominator = 1;}

        int getNumerator() const{return -1;};
        int getDenominator() const{return -1;};

        friend ostream &operator<<(std::ostream &os, const Fraction &f){
            os << f.numerator << "/" << f.denominator;
            return os;
        };

        friend Fraction operator+(const Fraction &f1, const Fraction &f2){return Fraction(1,1);};
        friend Fraction operator+(const Fraction &f, const float &d){return Fraction(1,1);};
        friend Fraction operator+(const float &d, const Fraction &f){return Fraction(1,1);};

        friend Fraction operator-(const Fraction &f1, const Fraction &f2){return Fraction(1,1);};
        friend Fraction operator-(const Fraction &f, const float &d){return Fraction(1,1);};
        friend Fraction operator-(const float &d, const Fraction &f){return Fraction(1,1);};

        friend Fraction operator/(const Fraction &f1, const Fraction &f2){return Fraction(1,1);};
        friend Fraction operator/(const Fraction &f, const float &d){return Fraction(1,1);};
        friend Fraction operator/(const float &d, const Fraction &f){return Fraction(1,1);};

        friend Fraction operator*(const Fraction &f1, const Fraction &f2){return Fraction(1,1);};
        friend Fraction operator*(const Fraction &f, const float &d){return Fraction(1,1);};
        friend Fraction operator*(const float &d, const Fraction &f){return Fraction(1,1);};

        friend bool operator<(const Fraction &f1, const Fraction &f2){return false;};
        friend bool operator<(const Fraction &f, const float &d){return false;};
        friend bool operator<(const float &d, const Fraction &f){return false;};

        friend bool operator>(const Fraction &f1, const Fraction &f2){return false;};
        friend bool operator>(const Fraction &f1, const float &d){return false;};
        friend bool operator>(const float &d, const Fraction &f){return false;};

        friend bool operator>=(const Fraction &f1, const Fraction &f2){return false;};
        friend bool operator>=(const Fraction &f1, const float &d){return false;};
        friend bool operator>=(const float &d, const Fraction &f){return false;};

        friend bool operator<=(const Fraction &f1, const Fraction &f2){return false;};
        friend bool operator<=(const Fraction &f1, const float &d){return false;};
        friend bool operator<=(const float &d, const Fraction &f){return false;};

        friend bool operator==(const Fraction &f1, const Fraction &f2){return false;};

        Fraction &operator++(){return *this;};
        Fraction operator++(int){return Fraction(1,1);};

        Fraction &operator--(){return *this;};
        Fraction operator--(int){return Fraction(1,1);};
    };
}
