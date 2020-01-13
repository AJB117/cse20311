#include <iostream>
using namespace std;

int main() {
	int a[10];
	int b[5];
	int c[] = {1,2,3,4,5,6, -1};	// Allowed; sentinel value at the end
	// int d[];						// Not allowed; size not defined and values not init'd

	for (int i = 0; i < 10; i++) {
		a[i] = 2*i + 1;
	}

	cout << "a array with initial values: " << endl;				// Printing values intialized in 10-12
	for (int j = 0; j < 10; j++) {
		cout << a[j] << " ";
	}

	cout << endl << "b array without initial values: " << endl;		// Printing garbage from memory
	for (int k = 0; k < 10; k++) {
		cout << b[k] << " ";
	}

	cout << endl << "c array indexing: " << endl;					// Using a sentinel value to iterate
	int index = 0;
	while (c[index] > 0) {
		cout << c[index] << " ";
		index++;
	}
	cout << endl;
	int csize = index;
	return 0;
}
