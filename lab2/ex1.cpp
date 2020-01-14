#include <iostream>
using namespace std;
#include <cmath>

int main()
{
	double a, b, c, disc;
	double x1, x2;

	cout << "Enter the coefficients (a,b,c) of a quadratic equation: ";
	cin >> a >> b >> c;
	
	disc = pow(b, 2) - (4 * a * c);
	if (disc > 0) {
		x1 = ((b * -1) + sqrt(disc))/(2 * a);
		x2 = ((b * -1) - sqrt(disc))/(2 * a);
		cout << "The first solution is: " << x1 << endl;
		cout << "The second solution is: " << x2 << endl;
	}
	else if (disc == 0) {
		x1 = ((b * -1) + sqrt(disc))/(2 * a);
		cout << "The only solution is: " << x1 << endl;
	}
	else {
		cout << "There are no real solutions" << endl;
	}

	return 0;
}
