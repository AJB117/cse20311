// Patrick Soga
// Section 2  Lab 7
// 3 November 2019
// states.cpp: implementation for state class

#include "state.h"
#include <string>
#include <iostream>
using namespace std;

// Constructors and destructor
State::State() {
    (*this).abbrev = "";
    (*this).name = "";
    (*this).capital = "";
    (*this).population = 0;
    (*this).foundYear = 0;
    (*this).numReps = 0;
};
State::State(string abbrev, string name, string capital, int population, int foundYear, int numReps) {
    (*this).abbrev = abbrev;
    (*this).name = name;
    (*this).capital = capital;
    (*this).population = population;
    (*this).foundYear = foundYear;
    (*this).numReps = numReps;
};
State::~State() {

// Getters and setters
};
void State::setAbbrev(string abbrev) {
    (*this).abbrev = abbrev;
};
string State::getAbbrev() {
    return (*this).abbrev;
};
void State::setName(string name) {
    (*this).name = name;
};
string State::getName() {
    return (*this).name;
};
void State::setCapital(string capital) {
    (*this).capital = capital;
};
string State::getCapital() {
    return (*this).capital;
};
void State::setPopulation(int population) {
    (*this).population = population;
};
int State::getPopulation() {
    return (*this).population;
};
void State::setFoundYear(int foundYear) {
    (*this).foundYear = foundYear;
};
int State::getFoundYear() {
    return (*this).foundYear;
};
void State::setNumReps(int numReps) {
    (*this).numReps = numReps;
};
int State::getNumReps() {
    return (*this).numReps;
};

// Utility functions

// Compare populations of two states
string State::comparePopulation(State s) {
    if (s.getPopulation() < (*this).getPopulation())
        return (*this).getAbbrev();
    else if(s.getPopulation() > (*this).getPopulation())
        return s.getAbbrev();
    else return "equal";
}

// Compare recency of statehood; older state is returned
string State::compareRecency(State s) {
    if (s.getFoundYear() > (*this).getFoundYear())
        return (*this).getAbbrev();
    else if(s.getFoundYear() < (*this).getFoundYear())
        return s.getAbbrev();
    else return "same age";
}

// Return number of people represented per representative
int State::represented() {
    return ((*this).getPopulation()/(*this).getNumReps());
}

// Return percentage of state population to population of another region
float State::percentageOf(int p) {
    return 100*((float)(*this).getPopulation()/p);
}