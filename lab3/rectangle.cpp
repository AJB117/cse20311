// Patrick Soga
// Section 2 Lab 3
// 16 September 2019
// rectangle.cpp: program that calculates a rectangle's perimeter and area

#include <iostream>

using namespace std;

float find_perim(float, float);
float find_area(float, float);
void display(float, float);

int main() {
    float len, wid;
    float perim, area;

    cout << "enter the length: ";
    cin >> len;
    cout << "enter the width: ";
    cin >> wid;

    perim = find_perim(len, wid); // call the find_perim function
    area = find_area(len, wid); // call the find_area function

    display(perim, area); // call the display function

    return 0;
}

float find_perim(float len, float width) {
    return (2 * len) + (2 * width);
};
float find_area(float len, float width) {
    return (len * width);
};
void display(float perim, float area) {
    cout << "Perimeter: " << perim << endl;
    cout << "Area: " << area << endl;
};
