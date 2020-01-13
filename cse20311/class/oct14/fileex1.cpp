#include <iostream>
using namespace std;
#include <string>
#include <fstream>

int main() {
	ifstream ifs;
	string filename;
	int a, b, c;
	
	cout << "Enter a file name: ";
	cin >> filename;
	
	// ifstream ifs(filename);
	ifs.open(filename);				// post-2011 allows C++ strings
	if(!ifs) {						// ifs returns null on error; checking !ifs.open() also works
		cout << "error" << endl;
		return 1;
	}

	ifs >> a >> b >> c;				// spaces and \n chars are delimeters
	cout << "numbers are: " << a << ", " << b << ", " << c << endl;	
	return 0;
}
