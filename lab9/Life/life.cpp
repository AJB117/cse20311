// Patrick Soga
// Section 2 Lab 9
// 17 November 2019
// life.cpp: Conway's Game of Life driver

#include <iostream>
#include <fstream>
#include <unistd.h>
#include <string>
#include "lifeboard.h"
using namespace std;

void interactiveGateway(Lifeboard&);
void prompt();
void interactiveDecider(Lifeboard&, char);

void batchGateway(Lifeboard&, char**);
void batchDecider(Lifeboard&, string);

int main(int argc, char *argv[]) {
    Lifeboard board;

    // Interactive mode
    if (argc == 1)
        interactiveGateway(board);
    // Bath mode
    else if (argc == 2)
        batchGateway(board, argv);
    else {
        cout << "Either run without arguments or run with a valid data file" << endl;
        return 2;
    }
    return 0;
}

void interactiveGateway(Lifeboard &board) {
    cout << "Welcome to Conway's Game of Life." << endl;
        prompt();
        char choice;
        cin >> choice;
        while (choice == 'a' || choice == 'r' || choice == 'n' || choice == 'p') {
            interactiveDecider(board, choice);
            prompt();
            cin >> choice;
        }
        if (choice == 'q') cout << "Goodbye!" << endl;
        else cout << "Invalid input" << endl;
}
void prompt() {
        cout << "Enter options: " << endl;
        cout << " a : spawn cell at coordinates." << endl
            << " r : kill cell at coordinates." << endl
            << " n : next iteration." << endl
            << " q : quit." << endl
            << " p : play the game." << endl;
}
void interactiveDecider(Lifeboard& board, char choice) {
    int x, y;
    Lifeboard referenceBoard = board;
    if (choice != 'a' && choice != 'r' && choice != 'n' && choice != 'q' && choice != 'p') {
        cout << "Invalid input" << endl;
        return;
    }
    else {
        switch(choice) {
            case 'a':
                cout << "Enter row and column coordinates (upper-left to bottom-right): " << endl;
                cin >> x >> y;
                if (x > 39 || x < 0 || y > 39 || y < 0)
                    cout << "Enter valid row and column coordinates (0-39)" << endl << endl;
                else {
                    board.setCell(x, y, 'X');
                    board.display();
                }
            break;
            case 'r':
                cout << "Enter row and column coordinates (upper-left to bottom-right): " << endl;
                cin >> x >> y;
                if (x > 39 || x < 0 || y > 39 || y < 0)
                    cout << "Enter valid row and column coordinates (0-39)" << endl << endl;
                else {
                    board.setCell(x, y, ' ');
                    board.display();
                }
            break;
            case 'n':
                board.advance(referenceBoard);
                board.display();
                referenceBoard = board;
            break;
            case 'p':
                while(true) {
                    cout << "\033[2J\033[1;1H";
                    board.advance(referenceBoard);
                    board.display();
                    referenceBoard = board;
                    usleep(500000);
                }
            break;
        }
    }
    return;
}

void batchGateway(Lifeboard &board, char **argv) {
    ifstream ifs;
    ifs.open(argv[1]);
    if (!ifs) {
        cout << "Invalid data file" << endl;
        return;
    }
    else {
        string line;
        while(ifs.peek() != EOF) {
            getline(ifs, line);
            batchDecider(board, line);
        }
    }
}

void batchDecider(Lifeboard &board, string choice) {
    Lifeboard referenceBoard = board;
    int x, y;
    int index;
    switch(choice[0]) {
        case 'a':
            // Get row and column numbers from the line strings
            for (int i = 1; i < choice.length(); i++) {
                if (choice[i] == ' ' && i != 1) {
                    x = stoi(choice.substr(2, i-1));
                    index = i;
                }
            }
            y = stoi(choice.substr(index, choice.length()-index));
            board.setCell(x, y, 'X');
        break;
        case 'r':
            board.setCell(choice[2], choice[4], ' ');
        break;
        case 'n':
            board.advance(referenceBoard);
            referenceBoard = board;
        break;
        case 'q':
            board.display();
            return;
        break;
        case 'p':
            while(true) {
                cout << "\033[2J\033[1;1H";
                board.advance(referenceBoard);
                board.display();
                referenceBoard = board;
                usleep(100000);
            }
        break;
    }
}