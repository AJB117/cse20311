#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <math>
using namespace std;

vector<int> readStamps();
vector<int> readParcels();

int main() {
    vector<int> stamps = readStamps();
    vector<int> parcels = readParcels();
    vector<vector<int>> solutions;

    sort(stamps.begin(), stamps.end());

    for (int parcel : parcels) {
        // Starting from the right
        if (abs(parcel - stamps.at(0)) > abs(parcel - stamps.at(stamps.size()-1))) {
            for (auto it = stamps.end(); it != stamps.begin(); --it) {
                vector<int> solution;
                int n = 1;
                int currentNum = *it;
                if ((*it) <= parcel/2) {
                    while (parcel >= n*currentNum) {
                        n++;
                        currentNum *= n;
                    }
                }

            }
        }
        // Starting from the left
        else {

        }
    }

    return 0;
}

vector<int> readStamps() {
    ifstream ifs;
    string filename;
    int stamp;
    vector<int> stamps;
    cout << "Filename for stamp values: " << endl;
    cin >> filename;
    ifs.open(filename);
    if (!ifs) {
        cout << "Unable to read file" << endl;
    }
    else {
        ifs >> stamp;
        while(ifs.peek() != EOF) {
            stamps.push_back(stamp);
            cout << stamp << endl;
            ifs >> stamp;
        }
    }
    return stamps;
}

vector<int> readParcels() {
    ifstream ifs;
    string filename;
    int parcel;
    vector<int> parcels;
    cout << "Filename for parcel values: " << endl;
    cin >> filename;
    ifs.open(filename);
    if (!ifs) {
        cout << "Unable to read file" << endl;
    }
    else {
        ifs >> parcel;
        while(ifs.peek() != EOF) {
            parcels.push_back(parcel);
            cout << parcel << endl;
            ifs >> parcel;
        }
    }
    return parcels;
}