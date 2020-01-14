// simple driver to test the Rational class

// Patrick Soga
// Section 2  Lab 8
// 10 November 2019
// rationalmain.cpp: driver for rational class tests
#include <iostream>
#include "rational.h"

using namespace std;

int main() {
  Rational a(5, 6), b(3, 7), c, s;

  cout << "*** display a and b ***\n";
  a.print();
  b.print();
  cout << "*** display c ***\n";
  c.print(); // recall that c was instantiated with the default constructor

  // 'mathematically' add a and b
  cout << "*** compute s as the math sum of a and b, and display s ***\n";
  s = a + b;
  cout << s;

  // 'mathematically' subtract a and b
  cout << "*** compute s as the math difference of a and b, and display s ***\n";
  s = a - b;
  cout << s;

  // 'mathematically' multiply a and b
  cout << "*** compute s as the math product of a and b, and display s ***\n";
  s = a * b;
  cout << s;

  // 'mathematically' divide a and b
  cout << "*** compute s as the math quotient of a and b, and display s ***\n";
  s = a / b;
  cout << s;

  // reduce a fraction f
  cout << "*** display a fraction f in its simplest form using overloaded << operator ***\n";
  Rational f1(6,3);
  cout << f1;

  cout << "*** display a fraction f in its simplest form from the overloaded >> operator ***\n";
  Rational f2;
  cin >> f2;
  cout << f2;
  return 0;
}