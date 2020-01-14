#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int sumSquares;
	double sumRoots;

	for (int i = 1; i < 11; ++i) {
		sumSquares += pow(i, 2);
		sumRoots += sqrt(i);
	}

	cout << "The sum of the squares between 1 and 10 is: " << sumSquares << endl;
	cout << "The sum of the square roots between 1 and 10 is: " << sumRoots << endl;

	return 0;
}
