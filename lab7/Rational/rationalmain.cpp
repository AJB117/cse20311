// simple driver to test the Rational class

// Patrick Soga
// Section 2  Lab 7
// 3 November 2019
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
  s = a.add(b);
  s.print();

  // 'mathematically' subtract a and b
  cout << "*** compute s as the math difference of a and b, and display s ***\n";
  s = a.subtract(b);
  s.print();

  // 'mathematically' multiply a and b
  cout << "*** compute s as the math product of a and b, and display s ***\n";
  s = a.multiply(b);
  s.print();

  // 'mathematically' divide a and b
  cout << "*** compute s as the math quotient of a and b, and display s ***\n";
  s = a.divide(b);
  s.print();

  return 0;
}