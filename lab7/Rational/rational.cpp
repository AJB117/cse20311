// Patrick Soga
// Section 2  Lab 7
// 3 November 2019
// rational.cpp: rational class implementation
#include <iostream>
#include "rational.h"
#include <iostream>
using namespace std;

// Private fields: numer, denom
Rational::Rational() {
    (*this).numer = 1;
    (*this).denom = 1;
};
Rational::Rational(int numer, int denom) { 
    (*this).numer = numer;
    (*this).denom = denom;    
};
Rational::~Rational() { 

};
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
void Rational::print() { 
    cout << numer << "/" << denom << endl;
};

// For add and subtract methods, the math differs depending on the denominator
Rational Rational::add(Rational r) { 
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
Rational Rational::subtract(Rational r) { 
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
Rational Rational::multiply(Rational r) { 
    int num = (*this).numer * r.numer;
    int den = (*this).denom * r.denom;
    return Rational(num, den);
};
Rational Rational::divide(Rational r) { 
    int num = (*this).numer * r.denom;
    int den = (*this).denom * r.numer;
    return Rational(num, den);
};