// Patrick Soga
// Section 2  Lab 8
// 10 November 2019
// rational.cpp: rational class implementation
#include <iostream>
#include <algorithm>
#include "rational.h"
using namespace std;

// Constructors and destructor
Rational::Rational() {
    (*this).setNumer(1);
    (*this).setDenom(1);
};
Rational::Rational(int numer, int denom) { 
    (*this).setNumer(numer);
    (*this).setDenom(denom);    
};
Rational::~Rational() { };
// Getters, setters, and utility
int Rational::getNumer() { 
    return (*this).numer;
};
int Rational::getDenom() { 
    return (*this).denom;
};
void Rational::setNumer(int numer) { 
    (*this).numer = numer;
};
void Rational::setDenom(int denom) { 
    (*this).denom = denom;
};

// void Rational::print() was deleted since << is overloaded

void Rational::setRational(int numer, int denom) {
    (*this).setNumer(numer);
    (*this).setDenom(denom); 
}

// Reduce fraction using <algorithm>'s __gcd() method
void Rational::reduce() {
    int gcd = __gcd((*this).getNumer(), (*this).getDenom());
    (*this).setNumer((*this).getNumer()/gcd);
    (*this).setDenom((*this).getDenom()/gcd);
}

// Math and overloaded methods
// For add and subtract methods, the math differs depending on the denominator
Rational Rational::operator+(Rational r) { 
    if ((*this).denom == r.denom) {
        int num = (*this).numer + r.numer;
        int den = (*this).denom;
        return Rational(num, den);
    }
    else {
        int num = ((*this).numer * r.denom) + (r.numer * (*this).denom);
        int den = (*this).denom * r.denom;
        return Rational(num, den);
    }
};
Rational Rational::operator-(Rational r) { 
    if ((*this).denom == r.denom) {
        int num = (*this).numer - r.numer;
        int den = (*this).denom;
        return Rational(num, den);
    }
    else {
        int num = ((*this).numer * r.denom) - (r.numer * (*this).denom);
        int den = (*this).denom * r.denom;
        return Rational(num, den);
    }
};
Rational Rational::operator*(Rational r) { 
    int num = (*this).numer * r.numer;
    int den = (*this).denom * r.denom;
    return Rational(num, den);
};
Rational Rational::operator/(Rational r) { 
    int num = (*this).numer * r.denom;
    int den = (*this).denom * r.numer;
    
    return Rational(num, den);
};

// Overloading ostream and istream
ostream & operator << (ostream & os, Rational & r) {
    r.reduce();
    os << r.getNumer() << "/" << r.getDenom() << endl;
    return os;
}
istream & operator >> (istream & is, Rational & r) {
    int numer, denom;
    cout << "Enter numerator and denominator: ";
    is >> numer >> denom;
    r.setRational(numer, denom);
    r.reduce();
    return is;
}
