// testcircle.cpp
// a main program to test the Circle class

// Patrick Soga
// Section 2  Lab 7
// 3 November 2019
// testcircle.cpp: driver for circle class tests
#include <iostream>
using namespace std;
 
#include "circle.h"

int main()
{
  Circle c1(7), c2;

  cout << "circle 1:" << endl;
  c1.info();

  cout << "circle 2:" << endl;
  c2.setRadius(5.2);
  c2.info();

  return 0;
}

