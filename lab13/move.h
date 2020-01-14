// Patrick Soga
// Lab 13, Section 2
// 15 Dec 2019
// move.h: Move interface

#include <string>
using namespace std;

class Move {
    public:
        // Constructors and destructor
        Move(string, int, string, string);
        Move();
        ~Move();
        // Getters and setters
        void setName(string); 
        string getName();
        void setBaseDamage(int);
        int getBaseDamage();
        void setType(string);
        string getType();
        void setCategory(string);
        string getCategory();
    private:
        string name;
        int baseDamage;
        string type;
        string category;
};