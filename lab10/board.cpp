// Patrick Soga
// Section 2 Lab 10
// 26 November 2019
// board.cpp: crossword board class implementation

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
#include <fstream>

#include "board.h"
using namespace std;
void sanitize(vector<string>&);
bool compare(string, string);
// Constructor, destructor, getters and setters
Board::Board() {
    (*this).setCols(15);
    (*this).setRows(15);
    vector<vector<char> > vect(((*this).getRows()), vector<char>((*this).getCols(), '.'));
    (*this).board = vect;
    (*this).puzzleBoard = vect;
}
Board::~Board() {}
void Board::setRows(int rows) {
    (*this).rows = rows;
}
void Board::setCols(int cols) {
    (*this).cols = cols;
}
int Board::getRows() {
    return (*this).rows;
}
int Board::getCols() {
    return (*this).cols;
}
char Board::getCell(int row, int col) {
    return (*this).board[row][col];
}
void Board::setCell(int row, int col, char c) {
    (*this).board[row][col] = c;
}

// Utility
bool Board::checkVertical(int row, int col, string s, int intersectRow, int intersectCol) {
    int length = s.size();  
    if (row + length < (*this).rows && row > 0) {
        // Check for overwriting a word
        if ((*this).board[row][col] != (*this).board[intersectRow][intersectCol] && (*this).board[row][col] != '.' && (*this).board[row][col] != ' ') {
            return false;
        }
        // // Check for incorrect overlap
        for (int i = 0; i < length; i++) {
            if (((*this).board[row + i][col] != '.' && (row + i) != intersectRow && (*this).board[row + i][col] != s[i]) || (*this).board[row + i][col] == ' ') {
                return false;
            }
        }
        // // Check top
        if ((*this).board[row-1][col] != '.' && (*this).board[row-1][col] != ' ') {
            return false;
        }
        // Check bottom
        if ((*this).board[row+length][col] != '.'  && (*this).board[row+length][col] != ' ') {
            return false;
        }
        // // Check corners surrounding intersection
        if (row < intersectRow) {
            if ((*this).board[intersectRow + 1][intersectCol + 1] != '.' || (*this).board[intersectRow + 1][intersectCol - 1] != '.' || (*this).board[row - 1][col+1] != '.' || (*this).board[row - 1][col-1] != '.') {
                return false;
            }
        }
        if (row == intersectRow) {
            if ((*this).board[intersectRow + 1][intersectCol + 1] != '.' || (*this).board[intersectRow + 1][intersectCol - 1] != '.') {
                return false;
            }
        }
    }
    else {
        return false;
    }    
    return true;
}
bool Board::checkHorizontal(int row, int col, string s, int intersectRow, int intersectCol) {
    int length = s.size();
    if (col + length < (*this).rows && col > 0) {
        // Check for overwriting a word
        if ((*this).board[row][col] != (*this).board[intersectRow][intersectCol] && (*this).board[row][col] != '.' && (*this).board[row][col] != ' ') {
            return false;
        }
        // Check for incorrect overlap
        for (int i = 0; i < length; i++) {
            if (((*this).board[row][col + i] != '.' && (*this).board[row][col+i] != '|') && ((col + i) != intersectCol) && ((*this).board[row][col + i] != s[i])) {
                return false;
            }
        }
        // Check front
        if ((*this).board[row][col-1] != '.' && (*this).board[row][col-1] != ' ') {
            return false;
        }
        // Check back
        if ((*this).board[row][col+length] != '.' && (*this).board[row][col+length] != ' ') {
            return false;
        } 
        // Check corners surrouding intersection
        if (col < intersectCol) {
            if ((*this).board[intersectRow + 1][intersectCol + 1] != '.' || (*this).board[intersectRow + 1][intersectCol - 1] != '.' || (*this).board[row - 1][col+1] != '.' || (*this).board[row - 1][col-1] != '.') {
                return false;
            }
        }
        if (col == intersectCol) {
            if ((*this).board[intersectRow + 1][intersectCol + 1] != '.' || (*this).board[intersectRow - 1][intersectCol + 1] != '.') {
                return false;
            }
        }
    }
    else {
        return false;
    }
    return true;
}
void Board::setVertical(int row, int col, string s) {
    if (s.size() < (*this).getRows() - 1) {
        (*this).setCell(row-1, col, ' ');
        (*this).setCell(row+s.size(), col, ' ');
    }
    for (auto it = s.begin(); it < s.end(); ++it) {
        (*this).setCell(row + (it - s.begin()), col, *it);
    }
}
void Board::setHorizontal(int row, int col, string s) {
    if (s.size() < (*this).getCols() - 1) {
        (*this).setCell(row, col - 1, ' ');
        (*this).setCell(row, col+s.size(), ' ');
    }
    for (auto it = s.begin(); it < s.end(); ++it) {
        (*this).setCell(row, col + (it - s.begin()), *it);
    }
}
void Board::print(vector<string> words, vector<vector<int> > wordData, int readWrite, string outputFile, vector<string> failedWords) {
    if (readWrite) {
        if (outputFile != "none") {
            // Redirect cout to output file
            // Solution from Stack Overflow (https://stackoverflow.com/questions/10150468/how-to-redirect-cin-and-cout-to-files)
            ofstream out(outputFile);
            streambuf *coutbuf = cout.rdbuf();
            cout.rdbuf(out.rdbuf());
            output(words, wordData, failedWords);
            cout.rdbuf(coutbuf);
        }
    }
    else
        output(words, wordData, failedWords);
}
void Board::output(vector<string> words, vector<vector<int> > wordData, vector<string> failedWords) {
    // Print out the failed words
    for (string word: failedWords)
        cout << "\"" << word << "\" cannot fit" << endl; 
    cout << endl << "SOLUTION:" << endl;
    for (int i = 0; i < (*this).getRows()+2; i++)
        cout << "-";
    cout << endl;
    for (int i = 0; i < (*this).getRows(); i++) {
        for (int j = 0; j < (*this).getCols(); j++) {
            if (j == 0)
                cout << "|";
            if ((*this).getCell(i ,j) == ' ')
                (*this).setCell(i, j, '.');
            cout << (char)toupper(getCell(i,j));
            if (j == (*this).getCols() - 1)
                cout << "|" << endl;
        }
    }
    for (int i = 0; i < (*this).getRows()+2; i++) {
        cout << "-";
    }
    cout << endl;
    cout << "PUZZLE:" << endl;
    for (int i = 0; i < (*this).getRows()+2; i++)
        cout << "-";
    cout << endl;
    for (int i = 0; i < (*this).getRows(); i++) {
        for (int j = 0; j < (*this).getCols(); j++) {
            if (j == 0)
                cout << "|";
            if (getCell(i, j) == '.' || getCell(i, j) == ' ')
                cout << '#';
            else cout << ' ';
            if (j == (*this).getCols() - 1)
                cout << "|" << endl;
        }
    }
    for (int i = 0; i < (*this).getRows()+2; i++) {
        cout << "-";
    }
    cout << endl << endl;
    cout << "Clues:" << endl << endl;
    cout << "Direction | Location | Anagram" << endl;
    cout << "------------------------------" << endl;
    for (int i = 0; i < words.size(); i++) {
        random_shuffle(words[i].begin(), words[i].end());
        if (wordData[i][3] == 0) {
            cout << setw(11) << "Across |";
            cout << setw(4) << wordData[i][0] << ", " << setw(3) << wordData[i][1] << " |";
        }
        else if (wordData[i][3] == 1) {
            cout << setw(11) << "Down |";
            cout << setw(4) << wordData[i][0] << ", " << setw(3) << wordData[i][1] << " |";
        }
        if (wordData[i][3] != -1)
            cout << " "<< words[i] << setw(15) << endl;
    }
}
void Board::generateBoard(vector<string> words, int readWrite, string outputFile) {
    // List of words that couldn't make it to the board
    vector<string> failedWords;  
    // Sanitize words and sort them based on length
    sanitize(words);
    sort(words.begin(), words.end(), compare);

    // Center the longest word
    (*this).setHorizontal(floor((*this).getRows()/2), floor((*this).getCols()/2) - floor(words[0].size()/2), words[0]);
    // Data vector containing clue information <row, col, length, orientation (0=horiz, 1=vert)>
    vector<vector<int> > wordData;
    (*this).addWord(floor((*this).getRows()/2), floor((*this).getCols()/2) - floor(words[0].size()/2), words[0].size(), 0, wordData);
    // Use only the words in addition to the centered word
    auto b = words.begin() + 1;
    auto e = words.begin() + words.size();
    vector<string> ws(b, e);
    // For every word, try to fit it and put the ones that fail into failedWords
    for (string word: ws) {
        fit(ws, word, wordData, failedWords);
    }
    (*this).print(words, wordData, readWrite, outputFile, failedWords);
}
// Fit a word onto the board
void Board::fit(vector<string> &words, string word, vector<vector<int> > &wordData, vector<string> &failedWords) {
    int size = wordData.size();
    bool found = false;
    for (int k = 0; k < wordData.size(); k++) {
        // On-board word that is being compared with
        string reference = "";
        // rowIndex and colIndex: indices of the first character of the current on-board word being compared
        int rowIndex = wordData[k][0];
        int colIndex = wordData[k][1];
        // row and col: indices of the first character of the new word to be placed
        int row, col;
        for (int i = 0; i < wordData[k][2]; i++) {
            if (wordData[k][3] == 0)
                reference += (*this).board[rowIndex][colIndex + i];
            else reference += (*this).board[rowIndex+i][colIndex];
        }
        for (int i = 0; i < word.size(); i++) {
            auto commonChar = find(reference.begin(), reference.end(), word[i]);
            if (commonChar != reference.end()) {
                if (wordData[k][3] == 0) {
                    row = rowIndex - word.substr(0, i).size();
                    col =  colIndex + (commonChar - reference.begin());
                    if ((*this).checkVertical(row, col, word, rowIndex, col)) {
                        (*this).setVertical(row, col, word);
                        (*this).addWord(row, col, word.size(), 1, wordData);
                        found = true;
                        break;
                    }
                    else {}
                }
                else {
                    int row = rowIndex + (commonChar-reference.begin());
                    int col = colIndex - word.substr(0, i).size();
                    if ((*this).checkHorizontal(row, col, word, row, colIndex)) {
                        (*this).setHorizontal(row, col, word);
                        (*this).addWord(row, col, word.size(), 0, wordData);
                        found = true;
                        break;
                    }
                    else {}
                }
            }
        }
        // Stop placing words after all the words in the inital wordData are checked
        if (k == size - 1) {
            break;
        }
        // Ensure a word is placed only once
        if (found) {
            break;
        }
    }
    if (!found) {
        failedWords.push_back(word);
        // auto w = find(words.begin(), words.end(), word);
        // words.erase(w);
        // All -1s signal a dead word to skip
        (*this).addWord(-1,-1,-1,-1, wordData);
    }
}

// Method for adding words to the board model
void Board::addWord(int row, int col, int length, int orientation, vector<vector<int> > &wordData) {
    vector<int> word;
    word.push_back(row);
    word.push_back(col);
    word.push_back(length);
    word.push_back(orientation);
    wordData.push_back(word);
}

// Clean word list of words that don't conform to spec
void sanitize(vector<string> &words) {
    vector<int> toDelete;
    for (int i = 0; i < words.size(); i++) {
        if (words[i].size() > 15 || words[i].size() == 1) {
            cout << "\"" << words[i] << "\" is invalid; must be shorter than 15 characters and longer than 1 character" << endl;
            toDelete.push_back(i);
        }
        for (int j = 0; j < words[i].size(); j++) {
            if (!isalpha(words[i][j])) {
                cout << "\"" << words[i] << "\" is invalid; must contain only alphabetical characters" << endl;
                toDelete.push_back(i);
                break;
            }
        }
    }
    for (int i: toDelete)
        words.erase(words.begin() + i);
}

// For sorting the words by length
bool compare(string s1, string s2) {
    return s1.size() > s2.size();
}