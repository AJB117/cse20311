// Patrick Soga
// Section 2 Lab 4
// 18 October 2019
// letterfreq.cpp: character analyzer for text files

#include <iostream>
#include <fstream>
#include <cctype>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    // Frequency for characters
    vector<int> frequency(26, 0);
    // Variables for statistics
    int totalChars = 0;
    int whiteSpace = 0;
    int letters = 0;

    string filename;
    char character;
    ifstream ifs;
    cout << "Enter the name of a file you want to analyze:" << endl;
    getline(cin, filename);
    ifs.open(filename);
    if (!ifs) {
        cout << "Invalid file" << endl;
    } else {
        while(ifs.get(character)) {
            character = tolower(character);
            if (isalpha(character)) {
                frequency.at(character - 97) += 1;
                letters++;
                totalChars++;
            }
            else if (isspace(character)) {
                whiteSpace++;
                totalChars++;
            }
            else totalChars++;              // Just increment if char is not a alphabetical nor a whitespace
        }
        // Alphabetical count output
        for (int i = 0; i < frequency.size(); i++) {
            // log10 for dynamic spacing based on the most numerous letter 'e'
            cout << setw(4) << (char)(i+97) << ":" << setw(log10(frequency.at(4)) + 2)  << frequency.at(i);
            if ((i+1) % 6 == 0) {
                cout << endl;
            } 
        }
        // Letter, character, and whitespace statistics
        cout << endl << "there were " << letters << " letters" << endl;
        cout << "there were " << totalChars << " total characters" << endl;
        cout << "there were " << whiteSpace << " white space characters" << endl;
        cout << "space percentage: " << fixed << setprecision(1) << ((whiteSpace / (float) totalChars) * 100) << "%" << endl;        
    }
    return 0;
}