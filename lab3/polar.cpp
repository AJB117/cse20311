// Patrick Soga
// Section 2 Lab 3
// 16 September 2019
// polar.cpp: program that converts Cartesian coordinates into polar coordinates
#include <iostream>
#include <cmath>
double get_radius(double, double);
double get_angle(double, double);
double radToDeg(double, double);
void quadrant_info(double, double);

using namespace std;

int main() {
    double x, y, radius, angle; 
    const double pi = 3.14159;
    cout << "Enter an x coordinate: ";
    cin >> x;
    cout << "Enter a y coordinate: ";
    cin >> y;

    radius = get_radius(x, y);
    angle = radToDeg(get_angle(x, y), pi);

    cout << "Radius: " << radius;
    cout << ". Angle: " << angle << " degrees" << endl;
    quadrant_info(x, y);
    
    return 0;
}

// Function to convert radians into degrees
double radToDeg(double angle, double pi) {
    return (angle * 180)/pi;
}

double get_radius(double x, double y) {
    double radius = sqrt(pow(x, 2) + pow(y, 2));
    return radius;
}

double get_angle(double x, double y) {
    double angle = atan2(y, x); // atan2() used since it's for converting Cartesian into polar
    return angle;
}

void quadrant_info(double x, double y) {
    // Origin and on-axis cases
    if (x == 0 && y == 0) {
        cout <<"This point is at the origin." << endl;
    }
    else if (x == 0) {
        cout << "This point is on the y-axis." << endl;
    }
    else if (y == 0) {
        cout << "This point is on the x-axis." << endl;
    }
    // Normal behavior
    else {
        if (x > 0 && y > 0) {
            cout << "This point is in quadrant I." << endl;
        }
        else if (x < 0 && y > 0) {
            cout << "This point is in quadrant II." << endl;
        }
        else if (x < 0 && y < 0) {
            cout << "This point is in quadrant III." << endl;
        }
        else {
            cout << "This point is in quadrant IV." << endl;
        }
    }

}
