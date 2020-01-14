// Patrick Soga
// Section 2 Lab 4
// 11 October 2019
// states1.cpp: Updated states demo program to use vectors and C++ strings
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// #include <cstring>  // Unneeded given iterators
 
int main() 
{
  string line1;
  string line2 = "notre dame fighting irish";
  vector<string> states = {"Indiana", "Michigan", "Ohio", "Illinois", "Iowa"};

  cout << "enter a line: ";
  getline(cin, line1);   // updated getline function 

  cout << "the first line is: " << line1 << endl;
  cout << "the second line is: " << line2 << endl;

  // display the states; using .at() to index the character needed
  cout << "the states are:" << endl;
  for (int i = 0; i < 5; i++)
    cout << " - " << states.at(i) << endl;

  // since we need to access each character here, we need nested for loops
  cout << "displaying the states with a space between letters:" << endl;
  for (int i = 0; i < 5; i++) {
    cout << " - ";
    for (int j = 0; j < states.at(i).length(); j++)
      cout << states.at(i).at(j) << " ";
    cout << endl;
  }

  return 0;
}
