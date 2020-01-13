#include <iostream>
using namespace std;

int main() {
	int n;
	cout << "Enter an intger: ";
	cin >> n;
	while (n != 0) {
		cout << n%10 << " ";
		n -= (n%10);
		n /= 10;
	}
	cout << endl;
	return 0;
}
