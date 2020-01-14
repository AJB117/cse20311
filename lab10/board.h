// Patrick Soga
// Section 2 Lab 10
// 26 November 2019
// board.h: crossword board class interface

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Board {
    private:
        vector<vector<char> > board;
        vector<vector<char> > puzzleBoard;
        vector<string> words;
        int rows;
        int cols;
    public:
    // Constructor, destructor, getters and setters
        Board();
        ~Board();
        void setRows(int);
        void setCols(int);
        int getRows();
        int getCols(); 
        char getCell(int, int);
        void setCell(int, int, char);

    // Utility
        bool checkVertical(int, int, string, int, int);
        bool checkHorizontal(int, int, string, int, int);
        void setVertical(int, int, string);
        void setHorizontal(int, int, string);
        void print(vector<string>, vector<vector<int> >, int, string, vector<string>);
        void output(vector<string>, vector<vector<int> >, vector<string>);
        void generateBoard(vector<string>, int, string);
        void fit(vector<string>&, string, vector<vector<int> >&, vector<string>&);
        void addWord(int, int, int, int, vector<vector<int> >&);
};