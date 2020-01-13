#include <iostream>
using namespace std;
#include <string>
#include <fstream>
#include <vector>

int main() {
    vector<int> v;
	ifstream ifs;
	string filename;
	
	cout << "Enter a file name: ";
	cin >> filename;
	
	// ifstream ifs(filename);
	ifs.open(filename);				// post-2011 allows C++ strings
	if(!ifs) {						// ifs returns null on error; checking !ifs.open() also works
		cout << "error" << endl;
		return 1;
	}

    int n;                          // numbers to be read from the file
    ifs >> n;                       // start reading from file
    while (!ifs.eof()) {
        v.push_back(n);
        cout << n << endl;          // printing the numbers as we go
        ifs >> n;                   // read the next number
    }

    cout << "there were " << v.size() << " numbers" << endl;
    cout << "they are: " << endl;
    for (auto it = v.begin(); it < v.end(); it++) {
        cout << *it << " ";
    }
	cout << endl;
	return 0;
}
