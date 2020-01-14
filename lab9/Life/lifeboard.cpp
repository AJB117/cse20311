// Patrick Soga
// Section 2 Lab 9
// 17 November 2019
// lifeboard.cpp: lifeboard class implementation

#include <iostream>
#include <vector>
#include "lifeboard.h"
using namespace std;

// Default constructor assumes x and y dimensions of 40
Lifeboard::Lifeboard() {
    vector<vector<char> > vect(40, vector<char>(40, ' '));
    (*this).board = vect;
    (*this).xdim = 40;
    (*this).ydim = 40;
};
Lifeboard::~Lifeboard() {};

// Getters and setters
void Lifeboard::setXdim(int xdim) {
    (*this).xdim = xdim;
};
void Lifeboard::setYdim(int ydim) {
    (*this).ydim = ydim;
};
int Lifeboard::getXdim() {
    return (*this).xdim;
};
int Lifeboard::getYdim() {
    return (*this).ydim;
};
void Lifeboard::setCell(int x, int y, char c) {
    (*this).board[x][y] = c;
};
char Lifeboard::getCell(int x, int y) {
    return (*this).board[x][y];
};

// Utility methods
void Lifeboard::advance(Lifeboard &refBoard) {
    for (int i = 0; i < (*this).xdim; i++) {
        for (int j = 0; j < (*this).ydim; j++) {
            int numNeighbors = refBoard.neighbors(i, j);
            if (refBoard.getCell(i, j) == 'X' && (numNeighbors == 2 || numNeighbors == 3)) {}
            else if (refBoard.getCell(i, j) == ' ' && numNeighbors == 3) (*this).setCell(i, j, 'X');
            else (*this).setCell(i, j, ' ');
        }
    }
};
int Lifeboard::neighbors(int x, int y) {
    int numNeighbors = 0;
    // right neighbor
    if (y + 1 < (*this).ydim && (*this).getCell(x, y+1) == 'X') 
        numNeighbors++;
    // left neighbor
    if (y - 1 >= 0 && (*this).getCell(x, y-1) == 'X') 
        numNeighbors++;
    // top neighbor
    if (x - 1 >= 0 && (*this).getCell(x-1, y) == 'X')
        numNeighbors++;
    // bottom neighbor
    if (x + 1 < (*this).xdim && (*this).getCell(x+1, y) == 'X')
        numNeighbors++;
    // top right neighbor
    if (x-1 >= 0 && y+1 < (*this).ydim && (*this).getCell(x-1, y+1) == 'X')
        numNeighbors++;
    // top left neighbor
    if (x-1 >= 0 && y-1 >=0 && (*this).getCell(x-1, y-1) == 'X')
        numNeighbors++;
    // bottom right neighbor
    if (x+1 < (*this).xdim && y+1 < (*this).ydim && (*this).getCell(x+1, y+1) == 'X')
        numNeighbors++;
    // bottom left neighbor
    if (x+1 < (*this).xdim && y-1 >= 0 && (*this).getCell(x+1, y-1) == 'X')
        numNeighbors++;
    return numNeighbors;
};
void Lifeboard::display() {
    for (int i = 0; i < 42; i++) {
        cout << "-";
    }
    cout << endl;
    for (int i = 0; i < 40; i++) {
        for (int j = 0; j < 40; j++) {
            if (j == 0) cout << "|";
            cout << (*this).getCell(i, j);
            if (j == 39) cout << "|" << endl;
        }
    }
    for (int i = 0; i < 42; i++) {
        cout << "-";
    }
    cout << endl;
};