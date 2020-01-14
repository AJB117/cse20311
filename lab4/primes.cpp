// Patrick Soga
// Section 2 Lab 4
// 27 September 2019
// primes.cpp: program to find and print all primes in [2, 999]

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
	// Find the primes
	int size = 1000;
	int count = 0;
	int elements[size];
	for (int i = 2; i < size; i++) {
		elements[i] = 1;
	}
	for (int j = 2; j < sqrt(size); j++) {				// Sieve only requires iterating up to sqrt(n)
		if (elements[j]) {
			for (int k = 0; k < size; k++) {
				if (j * j + (j * k) < size) {			// Only cross out values when within bounds of array
					count++;
					elements[(j * j) + (j * k)] = 0;	// Cross out every entry whose index is a multiple of current index
				}
			}
		}
	}

	// Output the primes
	int primes[count];
	int c = 0;											// Count to ensure primes are printed in order
	for (int n = 0; n < size; n++) {	
		if (elements[n]) {
			// Print end line every 10 primes
			if (c % 10 == 0 && c > 0) {
				cout << endl;
			}
			primes[c] = n;
			cout << setw(3) << primes[c] << "  ";
			c++;
		}
	}
	cout << endl;
	return 0;
}