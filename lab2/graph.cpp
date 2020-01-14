// Patrick Soga
// Section 2 Lab 2
// Week of 9 Sep 2019
// graph.cpp: program to graph ascii art of abs(x^2 * sin(3x))
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    // Value of function
    float y = 0;
    // Min and maximum y
    float minY = INFINITY;
    float maxY = 0;
    // Min and max x values
    float minX, maxX;
    // Scaling factor so that not too many #s appear
    float scale = 0.25;
    // Interval and step size
    float lowerBound = 0.0;
    float upperBound = 20.0;
    float step = 0.1;

    cout << "A plot of y = abs(x^2 * sin(3x)) from x=0 to x=20.0" << endl;
    cout << "       X       Y" << endl;
    for (float i = lowerBound; i <= upperBound+step; i+=step) {
        y = abs(i*i*sin(3*i));
        // Record rolling min and max y and corresponding x values
        if (maxY < y) {
            maxY = y;
            maxX = i;
        }
        if (minY > y) {
            minY = y;
            minX = i;
        }
        cout << fixed << setprecision(2) << setw(8) << i << setw(8) << y << setw(2) << " ";
        for (int j = 0; j < y * scale; j++) {
            cout << "#";
        }
        cout << endl;
    }
    cout << endl;
    cout << "The maximum of " << maxY << " was at x=" << maxX << endl;
    cout << "The minimum of " << minX << " was at x=" << minX << endl;

    return 0;
}
