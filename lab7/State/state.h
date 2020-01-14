// Patrick Soga
// Section 2  Lab 7
// 3 November 2019
// state.h: interface for state class

#include <string>
using namespace std;

class State {
    public:
        // Constructors and destructor
        State();
        State(string, string, string, int, int, int);
        ~State();
        // Getters and setters
        void setAbbrev(string);
        string getAbbrev();
        void setName(string);
        string getName();
        void setCapital(string);
        string getCapital();
        void setPopulation(int);
        int getPopulation();
        void setFoundYear(int);
        int getFoundYear();
        void setNumReps(int);
        int getNumReps();

        // Utility functions
        string comparePopulation(State);
        string compareRecency(State);
        int represented();
        float percentageOf(int);
    private:
        string abbrev;
        string name;
        string capital;
        int population;
        int foundYear;
        int numReps;
};