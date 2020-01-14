// Patrick Soga
// Section 2 Lab 4
// 11 October 2019
// states1.cpp: Updated states demo program to use vectors and C++ strings. Iterators only;
//              no indexing
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

  // display the states using an interator
  cout << "the states are:" << endl;
  for (auto it = states.begin(); it < states.end(); ++it)
    cout << " - " << *it << endl;

  // since we need to access each character here, we need to dereference the pointer per state pointer
  cout << "displaying the states with a space between letters:" << endl;
  for (auto it = states.begin(); it < states.end(); ++it) {
    cout << " - ";
    for (auto word_it = (*it).begin(); word_it < (*it).end(); ++word_it)
     	cout << *word_it << " ";
	cout << endl;
 }

  return 0;
}
