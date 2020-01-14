// Patrick Soga
// Section 2 Lab 1
// Week of 2 Sep 2019
#include <iostream>
#include <cmath> 	// For square root and power functions
using namespace std;

int main() { 		// Calculates distance between two points on a plane
	float p1x, p1y, p2x, p2y, subtractedx, subtractedy, distance;
	cout << "Enter the x and y coordinates of the first point: " << endl;
	cin >> p1x;
	cin >> p1y;
	cout << "Enter the x and y coordinates of the second point: " << endl;
	cin >> p2x;
	cin >> p2y;

			// Calculate differences in coordinates before squaring and summing
	subtractedx = p2x - p1x;
	subtractedy = p2y - p1y;
			
			// Pythagorean theorem using the differences in coordinates
	distance = sqrt(pow(subtractedx, 2) + pow(subtractedy, 2));
	cout << "The distance between the two points entered is: " << distance << endl; 
		
	return 0;
}
