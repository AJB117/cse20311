// Patrick Soga
// Section 2 Lab 10
// 26 November 2019
// crossword.cpp: crossword driver

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "board.h"
using namespace std;

void interactive();
bool read(string);
bool readWrite(string, string);

int main(int argc, char *argv[]) {
    Board board;
    vector<string> words;
    string input;
    cout << "Anagram Crossword Puzzle Generator" << endl;
    cout << "----------------------------------" << endl << endl;
    if (argc == 1) {
        cout << "Enter a list of words followed by a \".\"" << endl;
        interactive();
    }   
    else if (argc == 2) {
        if (!read(argv[1])) {
            cout << "Something happened; unable to proceed with given file" << endl;
        }
    }
    else if (argc == 3) {
        if (!readWrite(argv[1], argv[2])) {
            cout << "Something happened; unable to proceed with given files" << endl;
        }
        else {
            cout << "See file " << argv[2] << " for output" << endl;
        }
    }
    else cout << "Please use with either one input file or one input file and an output file" << endl;
    return 0;
}

// Bare minimum for interactive user session
void interactive() {
    Board board;
    vector<string> words;
    string input;
    getline(cin, input);
    while (input != "." && words.size() != 20) {
        words.push_back(input);
        getline(cin, input);
    }
    for (int i = 0; i < words.size(); i++) {
        for (int j = 0; j < words[i].size(); j++) {
            words[i][j] = toupper(words[i][j]);
        }
    }
    board.generateBoard(words, 0, "none");
}

// interactive() with input file
bool read(string filename) {
    Board board;
    vector<string> words;
    string input;
    ifstream ifs;
    ifs.open(filename);
    if (!ifs) {
        cout << "Unble to read file" << endl;
        return false;
    }
    else {
        while(ifs.peek() != EOF) {
            getline(ifs, input);
            while (input != "." && words.size() != 20) {
                words.push_back(input);
                getline(ifs, input);
            }
        }
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[i].size(); j++) {
                words[i][j] = toupper(words[i][j]);
            }
        }
        board.generateBoard(words, 0, "none");
    }
    return true;
}

// read() with arguments for output file
bool readWrite(string inputFile, string outputFile) {
    Board board;
    vector<string> words;
    string input;
    ifstream ifs;
    ofstream ofs;
    ifs.open(inputFile);
    if (!ifs) {
        cout << "Unble to read file" << endl;
        return false;
    }
    else {
        while(ifs.peek() != EOF) {
            getline(ifs, input);
            while (input != "." && words.size() != 20) {
                words.push_back(input);
                getline(ifs, input);
            }
        }
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[i].size(); j++) {
                words[i][j] = toupper(words[i][j]);
            }
        }
        board.generateBoard(words, 1, outputFile);
    }
    return true;
}