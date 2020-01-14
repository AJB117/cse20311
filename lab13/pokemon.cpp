// Patrick Soga
// Lab 13, Section 2
// 15 Dec 2019
// pokemon.cpp: Pokemon class


#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <cmath>
#include <fstream>
#include "gfx2.h"
#include "pokemon.h"

using namespace std;

// Constructors and destructor
Pokemon::Pokemon(string name, int level, int hp, float atk, float def, float spAtk, float spDef, float spd, vector<Move> moves, string type1, string type2, int frows, int fcols, int brows, int bcols) {
    setName(name);
    setLevel(level);
    setHp(hp);
    setAtk(atk);
    setDef(def);
    setSpAtk(spAtk);
    setSpDef(spDef);
    setSpd(spd);
    setMoves(moves);
    setType1(type1);
    setType2(type2);
    setBaseHp(hp);
    ifstream ifs;
    string n = name;
    (*this).frontColors.rows = frows;
    (*this).frontColors.cols = fcols;
    (*this).backColors.rows = brows;
    (*this).backColors.cols = bcols;    
    n[0] = tolower(n[0]);
    string filename = "./sprites/";
    // Load in pixel RGB values into front and back color structs
    // front
    ifs.open(filename + n + "/front" + "/" + n + "R.txt");
    if (!ifs)
        cout << "Unable to read file" << endl;
    else {
        while(ifs.peek() != EOF) {
            int r;
            ifs >> r;
            (*this).frontColors.red.push_back(r);
        }
    }
    ifs.close();
    ifs.open(filename + n + "/front" + "/" + n + "G.txt");
    if (!ifs)
        cout << "Unable to read file" << endl;
    else {
        while(ifs.peek() != EOF) {
            int r;
            ifs >> r;
            (*this).frontColors.green.push_back(r);
        }
    }
    ifs.close();
    ifs.open(filename + n + "/front" + "/" + n + "B.txt");
    if (!ifs)
        cout << "Unable to read file" << endl;
    else {
        while(ifs.peek() != EOF) {
            int r;
            ifs >> r;
            (*this).frontColors.blue.push_back(r);
        }
    }
    ifs.close();

    // back
    ifs.open(filename + n + "/back" + "/" + n + "R.txt");
    if (!ifs)
        cout << "Unable to read file" << endl;
    else {
        while(ifs.peek() != EOF) {
            int r;
            ifs >> r;
            (*this).backColors.red.push_back(r);
        }
    }
    ifs.close();
    ifs.open(filename + n + "/back" + "/" + n + "G.txt");
    if (!ifs)
        cout << "Unable to read file" << endl;
    else {
        while(ifs.peek() != EOF) {
            int r;
            ifs >> r;
            (*this).backColors.green.push_back(r);
        }
    }
    ifs.close();
    ifs.open(filename+ n + "/back" + "/" + n + "B.txt");
    if (!ifs)
        cout << "Unable to read file" << endl;
    else {
        while(ifs.peek() != EOF) {
            int r;
            ifs >> r;
            (*this).backColors.blue.push_back(r);
        }
    }
    ifs.close();

};
Pokemon::Pokemon() {
    setName("empty");
    setLevel(0);
    setHp(0);
    setAtk(0);
    setDef(0);
    setSpAtk(0);
    setSpDef(0);
    setSpd(0);
    setType1("empty");
    setType2("empty");
    setBaseHp(0);
}
Pokemon::~Pokemon() {};

// Getters/setters
void Pokemon::setName(string name) {
    (*this).name = name;
}

string Pokemon::getName() {
    return (*this).name;
}
void Pokemon::setLevel(int level) {(*this).level = level;}
int Pokemon::getLevel() {return (*this).level;}
void Pokemon::setHp(int hp) {(*this).hp = hp;}
int Pokemon::getHp() {return (*this).hp;}
void Pokemon::setAtk(float atk) {(*this).atk = atk;}
float Pokemon::getAtk() {return (*this).atk;}
void Pokemon::setDef(float def) {(*this).def = def;}
float Pokemon::getDef() {return (*this).def;}
void Pokemon::setSpDef(float spDef) {(*this).spDef = spDef;}
float Pokemon::getSpDef() {return (*this).spDef;}
void Pokemon::setSpAtk(float spAtk) {(*this).spAtk = spAtk;}
float Pokemon::getSpAtk() {return (*this).spAtk;}
void Pokemon::setSpd(float spd) {(*this).spd = spd;}
float Pokemon::getSpd() {return (*this).spd;}
void Pokemon::setMoves(vector<Move> moves) {(*this).moves = moves;}
vector<Move> Pokemon::getMoves() {return (*this).moves;}
void Pokemon::setType1(string type1) {(*this).type1 = type1;}
string Pokemon::getType1() {return (*this).type1;}
void Pokemon::setType2(string type2) {(*this).type2 = type2;}
string Pokemon::getType2() {return (*this).type2;}
void Pokemon::setBaseHp(int baseHp) {(*this).baseHp = baseHp;}
int Pokemon::getBaseHp() {return (*this).baseHp;}
// Utility

// Produce sprite
void Pokemon::draw(int x, int y, bool orientation) {
    string levelText = "Lvl: " + to_string(level);
    if (orientation) {
        gfx_color(0,0,0);
        gfx_text(10, 10, name.c_str());
        gfx_text(80, 10, levelText.c_str());

        (*this).drawHealth(1, 100);
        for (int i = 0; i < (*this).frontColors.rows; i++) {
            for (int j = 0; j < (*this).frontColors.cols; j++) {
                // Only works for greyscale; for extensibility, use green and blue vectors if using colored sprites
                int color = (*this).frontColors.red[j+(*this).frontColors.cols*i]; 
                gfx_color(color, color, color); 
                gfx_point(i + x, j + y);
            }
        }
    }
    else {
        gfx_color(0,0,0);
        gfx_text(gfx_windowwidth() - 150, gfx_windowheight() - 130, name.c_str());
        gfx_text(gfx_windowwidth() - 80, gfx_windowheight() - 130, levelText.c_str());

        (*this).drawHealth(0, 100);
        for (int i = 0; i < (*this).backColors.rows; i++) {
            for (int j = 0; j < (*this).backColors.cols; j++) {
                // Only works for greyscale; for extensibility, change if using colored sprites
                int color = (*this).backColors.red[j+(*this).backColors.cols*i];  
                gfx_color(color, color, color);
                gfx_point(i + x, j + y);
            }
        }
    }
}

void Pokemon::drawHealth(int orientation, int value) {
    if (orientation) {        
        gfx_color(0,0,0);
        gfx_rectangle(10, 20, 100, 4);
        gfx_color(0, 255, 0);
        gfx_fill_rectangle(10, 20, value, 1);
    }
    else {
        gfx_color(0,0,0);
        gfx_rectangle(gfx_windowwidth() - 150, gfx_windowheight() - 120, 100, 4);
        gfx_color(0, 255, 0);
        gfx_fill_rectangle(gfx_windowwidth() - 150, gfx_windowheight() - 120, value, 1);
    }
}

// Damage moves
void Pokemon::damage(int damage, int orientation) {
    int hp = (*this).getHp();
    int baseHp = (*this).getBaseHp();
    int value = ceil(100*(((float) hp - (float)damage)/baseHp));
    cout << value << endl;
    // Damage animation
    if (hp-damage < 0) {
        (*this).setHp(0);
        (*this).drawHealth(orientation, 0);
    }
    else {
        (*this).setHp(hp-damage);
        (*this).drawHealth(orientation, value);
    }
}
// Status moves
void Pokemon::status(Move move, Pokemon target, int orientation) {
    int hp = (*this).getHp();
    int baseHp = (*this).getBaseHp();
    float heal = baseHp*0.5;
    if (move.getName() == "Recover") {
        int hp = (*this).getHp();
        int baseHp = (*this).getBaseHp();
        if (hp + heal > hp) {
            cout << "Healed HP!" << endl;
            (*this).setHp(baseHp);
            (*this).drawHealth(orientation, 100);
        }
        else if (hp+heal == baseHp) {
            cout << "HP is full!" << endl;
            (*this).drawHealth(orientation, 100);
        }
        else {
            cout << " healed HP!" << endl;
            (*this).setHp(hp + heal);
            int value  = ceil(100*((float) hp + heal)/baseHp);
            (*this).drawHealth(orientation, value);
        }
    }
    else if (move.getName() == "Screech") {
        target.setDef(target.getSpDef()*0.75);
        cout << target.getName() << "'s Special Defense harshly fell!" << endl;
    }

}

// Overload to print Pokemon easily
ostream & operator << (ostream & os, Pokemon & p) {
    os << p.getName() << endl;
    os << "Level: " << p.getLevel() << endl;
    os << "HP: " << p.getHp() << endl;
    os << "Atk: " << p.getAtk() << endl;
    os << "Def: " << p.getDef() << endl;
    os << "SpAtk: " << p.getSpAtk() << endl;
    os << "SpDef: " << p.getSpDef() << endl;
    os << "Spd: " << p.getSpd() << endl;
    os << endl;
    
    for (Move move: p.getMoves()) {
        os << move.getName() << endl;
    }

    return os;
}