// Patrick Soga
// Lab 13, Section 2
// 15 Dec 2019
// move.cpp: Move class

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "gfx2.h"
#include "move.h"

using namespace std;

// Constructors and destructor
Move::Move(string name, int baseDamage, string type, string category) {
    setName(name);
    setBaseDamage(baseDamage);
    setType(type);
    setCategory(category);
};
Move::Move() {
    setName("empty");
    setBaseDamage(0);
    setType("empty");
    setCategory("empty");
};
Move::~Move(){};

// Getters and setters
void Move::setName(string name) { (*this).name = name; }
string Move::getName() { return (*this).name; }
void Move::setBaseDamage(int baseDamage) { (*this).baseDamage = baseDamage; }
int Move::getBaseDamage() { return (*this).baseDamage; }
void Move::setType(string type) {(*this).type = type;}
string Move::getType() {return (*this).type;}
void Move::setCategory(string category) { (*this).category = category;}
string Move::getCategory() { return category;}