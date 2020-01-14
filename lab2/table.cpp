// Patrick Soga
// Section 2 Lab 2
// Week of 9 Sep 2019
// table.cpp: program to print an mXn multiplication table
#include <iostream>
#include <iomanip>	// For setw() for getting the spacing right
using namespace std;

int main() {
	// Initialize and read in row and column numbers
	int x, y;
	cout << "Enter the number of columns you want for the table: ";
	cin >> x;
	cout << "Enter the number of rows you want for the table: ";
	cin >> y;

	for (int i = 0; i <= y; i++) {
		for (int j = 0; j <= x; j++) {
			if (i == 0 && j == 0) {
				cout << "   *" << setw(4);
			}
			if (i > 0 && j == 0) {
				cout << i << setw(4);
			}
			if (i == 0 && j > 0) {
				cout << j << setw(4);
			}
			if (i > 0 && j > 0) {
				cout << i*j << setw(4);
			}
		}
		cout << endl;
	}
	return 0;
}