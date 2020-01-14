// Patrick Soga
// Section 2 Lab 9
// 17 November 2019
// lifeboard.h: lifeboard class interface

#include <iostream>
#include <vector>
using namespace std;

class Lifeboard {
    public:
        Lifeboard();
        ~Lifeboard();
        Lifeboard(int, int);
        void setXdim(int);
        void setYdim(int);
        int getXdim();
        int getYdim();
        void setCell(int, int, char);
        char getCell(int, int);
        void advance(Lifeboard&);
        int neighbors(int, int);
        void display();
    private:
        vector< vector<char> > board;
        int xdim;
        int ydim;
};