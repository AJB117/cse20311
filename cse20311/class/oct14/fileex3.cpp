#include <iostream>
using namespace std;
#include <string>
#include <fstream>
#include <vector>

int main() {
    vector<int> v;
	ifstream ifs;
	string filename;
    ofstream ofs;
    string outfile;
	
    // Input
	cout << "Enter a file name: ";
	cin >> filename;
	
	// ifstream ifs(filename);
	ifs.open(filename);				// post-2011 allows C++ strings
	if(!ifs) {						// ifs returns null on error; checking !ifs.open() also works
		cout << "error opening file " << filename << endl;
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

    // Output
    cout << "enter the output file name: ";
    cin >> outfile;
    ofs.open(outfile);
    if(!ofs) {
        cout << "error opening file " << outfile << endl;
        return 2;
    }
    // getline(ifs, var) also works to read input from a file
	return 0;
}
