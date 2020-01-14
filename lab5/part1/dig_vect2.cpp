// Patrick Soga
// Section 2 Lab 4
// 11 October 2019
// dig_vect2.cpp: exercise 1 demo updated to use vectors with iterators without
//                indexing
#include <iostream>
#include <vector>
using namespace std;

void find_freqs(vector<int>&, vector<int>&);
void results(vector<int>&);

int main()
{
  // vector with random digits
  vector<int> digits = {4,3,6,5,7,8,9,4,6,3,1,3,5,7,6,3,6,
                  5,6,7,0,2,9,7,1,3,2,1,6,7,4,6,2,8,
                  1,4,5,6,0,2,7,6,4,5,6,8,3,5,7,1,5};

  // the freq array tallies the frequency of digits
  // iow: for each digit i from 0 to 9, freq[i] will contain 
  //   the number of i's that are in the digits[] array
  vector<int> freq(10, 0);  // initialize the vector to all 0's                

  find_freqs(digits, freq);  // compute digits' frequencies
  results(freq);               // display frequencies for each digit

  return 0;
}

void find_freqs(vector<int> &a, vector<int> &freq)
{
    for (auto a_it = a.begin(); a_it < a.end(); ++a_it) {
      auto freq_it = freq.begin();
      freq_it += *a_it;
      *freq_it += 1;
    }
}

void results(vector<int> &freq)
{
  for (auto it = freq.begin(); it < freq.end(); ++it) 
    cout <<  "digit " << distance(freq.begin(), it) << " occurs " << *it << " times" << endl;
}
