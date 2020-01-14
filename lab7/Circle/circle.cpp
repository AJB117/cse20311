// Patrick Soga
// Section 2  Lab 7
// 3 November 2019
// circle.cpp: Circle class implementation
#include "circle.h"
#include <cmath>
#include <iostream>
using namespace std;

Circle::Circle() {
    (*this).radius = 0;
}
Circle::Circle(float r) {
    (*this).radius = r;
}
Circle::~Circle() {

}
float Circle::getRadius() {
    return (*this).radius;
}
void Circle::setRadius(float r) {
    (*this).radius = r;
}
float Circle::circumference() {
    return (*this).radius * 2 * M_PI;
}
float Circle::area() {
    return (*this).radius * (*this).radius * M_PI;
}
void Circle::info() {
    cout << "  radius: " << (*this).radius << endl;
    cout << "  circumference: " << (*this).circumference() << endl;
    cout << "  area: " << (*this).area() << endl;

}