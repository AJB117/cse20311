// Patrick Soga
// Section 2  Lab 7
// 3 November 2019
// statemain.cpp: driver for State class terminal educational program

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include "state.h"
using namespace std;

int menu();
void decider(int, vector<State>);
void compare(vector<State>);
void representation(vector<State>);
void table(vector<State>);
void capitals(vector<State>);
void recency(vector<State>);

int main() {
    // Read in data setup
    ifstream ifs;
    int choice;
    string line;
    vector<State> states;
    string filename;
    cout << "Please enter a filename to read from: " << endl;
    getline(cin, filename);
    ifs.open(filename);
    if (!ifs) {
        cout << "Unable to read file" << endl;
        return 1;
    }
    else {
        while(ifs.peek() != EOF) {
            // Read off the comma-separated values and store in State objects
            string value = "";
            string name, abbrev, capital, population, foundYear, numReps;
            int p, y, r;
            getline(ifs, name, ',');
            getline(ifs, abbrev, ',');
            getline(ifs, capital, ',');
            getline(ifs, population, ',');
            getline(ifs, foundYear, ',');
            getline(ifs, numReps, '\n');
            p = stoi(population);
            y = stoi(foundYear);
            r = stoi(numReps);
            State s(name, abbrev, capital, p, y, r);
            states.push_back(s);
        }

        // Prompt user
        choice = menu();
        // Produce output depending on user input
        while (choice != 6) {
            decider(choice, states);
            choice = menu();
        }
    }
    return 0;
}

// Prompt
int menu() {
    int choice = -1;
    while (choice > 6 || choice < 0) {
        cout << "Please enter an option below for information on the states of the U.S.A." << endl;
        cout << "  1: compare two states' populations given their abbreviations" << endl;
        cout << "  2: representation ratio of a state given its abbreviation" << endl;
        cout << "  3: table of all states with their respective percentage of national population" << endl;
        cout << "  4: list all states with their capitals" << endl;
        cout << "  5: compare two states' recency given their abbreviations" << endl;
        cout << "  6: quit" << endl;
        cin >> choice;
        if(choice > 6 || choice < 0) {
            cout << "Invalid choice. Please enter another number." << endl;
        }
    }
    return choice;
}

// Operations based on user input
void decider(int choice, vector<State> states) {
    switch(choice) {
        // Compare state populations
        case 1: 
            compare(states);
        break;
        // Find people/representative ratio
        case 2:
            representation(states);
        break;
        // Print table with percentages relative to U.S. population
        case 3:
            table(states);
        break;
        // Print all capitals
        case 4:
            capitals(states);
        break;
        // Compare state recency
        case 5:
            recency(states);
        break;
        case 6:
            cout << "Goodbye!" << endl;
        break;
    }
}

void compare(vector<State> states) {
    State s1, s2;
    string abbrev1, abbrev2 = "";
    cout << "Enter the abbreviations (capitalized) of two states: " << endl;
    cin >> abbrev1 >> abbrev2;
    for (auto it = states.begin(); it < states.end(); ++it) {
        if ((*it).getAbbrev() == abbrev1)
            s1 = *it;
        else if ((*it).getAbbrev() == abbrev2)
            s2 = *it;
    }
    if (s1.getAbbrev() == "" || s2.getAbbrev() == "") {
        cout << endl << "One or more of the states you entered was invalid. Try again." << endl << endl;
        return;
    }
    else {
        cout << endl << "Between " << abbrev1 << " and " << abbrev2 << ", " << s1.comparePopulation(s2) << 
        " has more people. To compare, " << abbrev1 << " has " << s1.getPopulation() << " people and " <<
        abbrev2 << " has " << s2.getPopulation() << " people." << endl << endl;
    }  
}

void representation(vector<State> states) {
    State s;
    string abbrev;
    cout << "Enter the abbreviaiton (capitalized) of a state whose representation ratio you want to see: " << endl;
    cin >> abbrev;
    for (auto it = states.begin(); it < states.end(); ++it) {
        if ((*it).getAbbrev() == abbrev)
            s = *it;
    }
    if (s.getAbbrev() == "") {
        cout << endl << "The state you entered was invalid. Try again." << endl << endl;
        return;
    }
    else {
        cout << endl << "The representation ratio of " << s.getAbbrev() << " is: "
        << s.represented() << " people per representative." << endl;
        cout << "Population: " << s.getPopulation() << endl;
        cout << "Number of representatives: " << s.getNumReps() << endl << endl;
    }
}

void table(vector<State> states) {
    int totalPop = 0;
    for (auto it = states.begin(); it < states.end(); ++it)
        totalPop += (*it).getPopulation();
    cout << "      State     " << setw(12) << "Population" << setw(22) << "Percentage of USA" << setw(14) << endl;
    cout << "------------------------------------------------------" << setw(14) << endl;
    for (auto it = states.begin(); it < states.end(); ++it) {
        cout<< fixed << setprecision(2) << (*it).getName() << setw(12) << (*it).getPopulation() << setw(14) << (*it).percentageOf(totalPop) << " %" << setw(14) << endl;
    }
    cout << endl;
}

void capitals(vector<State> states) {
    int count = 0;
    cout << endl;
    for (auto it = states.begin(); it < states.end(); ++it) {
        count++;
        cout << left << setw(30) << (*it).getCapital() + ", " + (*it).getName();;
        if (count % 5 == 0)
            cout << endl;
    }
    cout << endl << endl;
}

void recency(vector<State> states) {
    string abbrev1, abbrev2 = "";
    State s1, s2;
    cout << "Enter the abbreviations (capitalized) of two states whose founded years you want to compare: " << endl;
    cin >> abbrev1 >> abbrev2;
    for (auto it = states.begin(); it < states.end(); ++it) {
        if ((*it).getAbbrev() == abbrev1)
            s1 = *it;
        else if ((*it).getAbbrev() == abbrev2)
            s2 = *it;
    }
    if (s1.getAbbrev() == "" || s2.getAbbrev() == "") {
        cout << endl << "One or more of the states you entered was invalid. Try again." << endl << endl;
        return;
    }
    else {
        cout << endl << "Between " << abbrev1 << " and " << abbrev2 << ", " << s1.compareRecency(s2) << " is more recent. "
        << abbrev1 << " was founded in " << s1.getFoundYear() << " while " << abbrev2 << " was founded in " << s2.getFoundYear()
        << endl << endl;
    }
}