// Patrick Soga
// Section 2 Lab 3
// 16 September 2019
// gcdmain.cpp: program that implements function to find the gcd of two integers
#include <iostream>
using namespace std;

int getgcd(int, int);

int main() {
    int int1, int2;
    cout << "Enter two positive integers to find their gcd. Integer 1: ";
    cin >> int1;
    cout << "Integer 2: ";
    cin >> int2;

    cout << "The gcd of " << int1 << " and " << int2 << " is " << getgcd(int1, int2) << endl;
    return 0;
}

int getgcd(int a, int b) {
    while (true) {
        // Trivial cases
        if (a == 0) {
            return b;
        } 
        else if (b == 0) {
            return a;
        }
        // Normal behavior; Euclid's algorithm
        else {
            int temp = a;
            a = b;
            b = (temp % b);
        }
    }
}