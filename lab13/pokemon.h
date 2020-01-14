// Patrick Soga
// Lab 13, Section 2
// 15 Dec 2019
// pokemon.h: Pokemon interface

#include <vector>
#include <string>
#include "move.h"
using namespace std;

struct colors {
    vector<int> red;
    vector<int> green;
    vector<int> blue;
    int rows;
    int cols;
};

class Pokemon {
    public:
        friend ostream & operator<< (ostream &os, Pokemon &);
        // Constructors and destructor
        Pokemon(string, int, int, float, float, float, float, float, vector<Move>, string, string, int, int, int, int);
        Pokemon();
        ~Pokemon();
        // Getters and setters
        void setName(string);
        string getName();
        void setLevel(int);
        int getLevel();
        void setHp(int);
        int getHp();
        void setAtk(float);
        float getAtk();
        void setDef(float);
        float getDef();
        void setSpDef(float);
        float getSpDef();
        void setSpAtk(float);
        float getSpAtk();
        void setSpd(float);
        float getSpd();
        void setMoves(vector<Move>);
        vector<Move> getMoves();
        void setType1(string);
        string getType1();
        void setType2(string);
        string getType2();
        void setBaseHp(int);
        int getBaseHp();
        void damage(int, int);
        void status(Move, Pokemon, int);
        void draw(int, int, bool);
        colors frontColors;
        colors backColors;
        void drawHealth(int, int);
    private:
        string name;
        int level;
        int hp; 
        int baseHp;
        float atk;
        float def;
        float spDef;
        float spAtk;
        float spd;
        vector<Move> moves;
        string type1;
        string type2;
};