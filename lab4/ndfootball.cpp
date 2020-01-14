// Patrick Soga
// Section 2 Lab 4
// 29 September 2019
// ndfootball.cpp: program for finding stats for ND football

#include <iostream>
#include <iomanip>
#include "nd_data.h"
using namespace std;

void mainMenu();
void decider(int, int[], int[], int);
int findRecord(int, int[], int[], int);
void findLosses(int[], int, int);
void findWins(int[], int, int);
void findTies(int[], int[], int);
void findOverallRecord(int, int[], int[], int);

int main() {
    int choice, ls, ws;
    int size = sizeof(losses)/sizeof(losses[0]);                       // No need to get size of both wins and losses since every
    mainMenu();                                                        // win record has a corresponding loss record and vice versa
    cin >> choice;
    while (true) {
        if (!(choice < 7)) {
            cout << "Error: enter a number between 1 and 6." << endl << endl;
        }
        else if (choice == 6) {
            decider(choice, wins, losses, size);
            break;
        }
        else {
            decider(choice, wins, losses, size);
        }
        mainMenu();
        cin >> choice;
    }
    return 0;
}
// TODO: if a record doesn't exist or input is invalid, say it
void mainMenu() {
    cout << "1: display the record for a given year." << endl;
    cout << "2: display years with at least \"n\" losses." << endl;
    cout << "3: display years with at least \"n\" wins." << endl;
    cout << "4: display years with ties." << endl;
    cout << "5: display overall record up to a given year." << endl;
    cout << "6: exit" << endl;
    cout << "Enter your choice: ";
}

void decider(int choice, int wins[], int losses[], int size) {
    int year, ws, ls;
    switch(choice) {
        case 1:
            cout << "Enter the year: ";
            cin >> year;
            findRecord(year, wins, losses, size);
        break;
        case 2:     
            cout << "Enter a minimum number of losses: ";
            cin >> ls;
            findLosses(losses, size, ls);
            break;
        case 3:
            cout << "Enter a minimum number of wins: ";
            cin >> ws;
            findWins(wins, size, ws);
            break;
        case 4:
            findTies(wins, losses, size);
            break;
        case 5:
            cout << "Enter the year: ";
            cin >> year;
            findOverallRecord(year, wins, losses, size);
            break;
        default:
            cout << "good bye!" << endl;
        break;
    }
}

int findRecord(int year, int wins[], int losses[], int size) {
    int yearWins, yearLosses;
    int offset = year - 1900;
    // Check if year is valid
    if (offset > size || offset < 0) {
        cout << "There are no records for this year." << endl << endl;
    }
    // Normal behavior
    else {
        yearWins = wins[offset];
        yearLosses = losses[offset];
        cout << "Wins: " << yearWins << ", Losses: " << yearLosses << endl << endl;
    }
}

void findLosses(int losses[], int size, int ls) {
    int tracker = 0;
    cout << "Years with at least " << ls << " losses: ";
    for (int i = 0; i < size; i++) {
        if (losses[i] >= ls) {
            tracker = (1900 + i);
            cout << (1900+i) << " "; 
        }
    }
    // If tracker remains 0, then there were no games with corresponding # wins
    if (tracker == 0) {
        cout << "There are no years with " << ls << " wins.";
    }
    cout << endl << endl;
}

void findWins(int wins[], int size, int ws) {
    int tracker = 0;
    cout << "Years with at least " << ws << " wins: ";
    for (int i = 0; i < size; i++) {
        if (wins[i] >= ws) {
            tracker = (1900 + i);
            cout << (1900+i) << " "; 
        }
    }
    // If tracker remains 0, then there were no games with corresponding # wins
    if (tracker == 0) {
        cout << "There are no years with " << ws << " wins.";
    }
    cout << endl << endl;
}

void findTies(int wins[], int losses[], int size) {
    cout << "Years with tied scores: " << endl;
    cout << setw(5) << "Year" << setw(7) << "Wins" << setw(8) << "Losses" << endl;
    cout << "--------------------" << endl;
    for (int i = 0; i < size; i++) {
        if (wins[i] == losses[i]) {
            cout << setw(5) << (1900 + i) << setw(6) << wins[i] << setw(8) << losses[i] << endl;
        }
    }
    // No need to check for years without tied scores since they already have occurred
    cout << endl;
}

void findOverallRecord(int year, int wins[], int losses[], int size) {
    int yearWins, yearLosses, offset;
    offset = year - 1900;
    // Check if year is valid
    if (offset > size || offset < 0) {
        cout << "Enter a valid year to find the overall record up to.";
    }
    // Normal behavior
    else {
        for (int i = 0; i < offset; i++) {
            cout << wins[i] << endl;
            cout << losses[i] << endl;
            yearWins += wins[i];
            yearLosses += losses[i];
        }
        cout << "Wins since " << year << ": " << yearWins << ", Losses since " << year << ": " << yearLosses;
    }
    cout << endl << endl;
}