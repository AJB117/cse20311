// Patrick Soga
// Section 2 Lab 4
// 27 September 2019
// grades.cpp: program to calculate and display a grade array's average and standard deviation
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

float average(int grades[], int numElements);
float stdDev(int grades[], int numElements, float average);

int main()
{
    float mean, standardDev;
    int grades[50] =
    { 96,73,62,87,80,63,93,79,71,99,
      82,83,80,97,89,82,93,92,95,89,
      71,97,91,95,63,81,76,98,64,86,
      74,79,98,82,77,68,87,70,75,97,
      71,94,68,87,79, -1 };
    
    int counter = 0.0;
    // While loop terminates upon encountering sentinel
    while (grades[counter] > 0) {
        counter++;
    }

    mean = average(grades, counter);
    standardDev = stdDev(grades, counter, mean);

    // Output
    cout << fixed << setprecision(2) << "There are " << counter << " grades." << endl;
    cout << "The average grade is: " << mean << endl;
    cout << "The standard deviation is: " << standardDev << endl;
    return 0;

}

float average(int grades[], int numElements) {
    float sum = 0;
    for (int i = 0; i < numElements; i++) {
        sum += grades[i];
    }
    return (sum / numElements);
}

float stdDev(int grades[], int numElements, float average) {
    float sumSquaredDiffs = 0;
    for (int i = 0; i < numElements; i++) {
        sumSquaredDiffs += pow(grades[i] - average, 2);
    }
    return sqrt(((float)1 / numElements) * sumSquaredDiffs);
}