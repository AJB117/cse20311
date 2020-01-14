// Patrick Soga
// Section 2 Lab 3
// 16 September 2019
// menucalc.cpp: text-based calculator
#include <iostream>
using namespace std;

float add(double, double);
float sub(double, double);
float mult(double, double);
float div(double, double);
void mainMenu();
int decider(int);

int main() {
    int choice;
    bool done = false;
    mainMenu();
    cin >> choice;
    while (!done) {
        // Exit and fail cases
        if (choice == 5) {
            break;
        }
        else if (choice > 5 || choice < 0) {
            cout << "Invalid input. Please try again with an integer between 1 and 5." << endl;
            break;
        }
        // Produce output
        decider(choice);
        mainMenu();
        cin >> choice;
    }
    // Exit message
    cout << "Good bye!" << endl;
    return 0;
}

// Menu display
void mainMenu() {
    cout << "What would you like to do?" << endl;
    cout << " 1 for addition" << endl;
    cout << " 2 for subtraction" << endl;
    cout << " 3 for multiplication" << endl;
    cout << " 4 for division" << endl;
    cout << " 5 for exit" << endl;
    cout << "Enter your choice: ";
    return;
}
// Output per choice
int decider(int choice) {
    double arg1, arg2;
    cout << "Enter two numbers: ";
    cin >> arg1;
    cin >> arg2;
    cout << "Inputs: " << arg1 << ", " << arg2 << endl;
        switch (choice) {
            case 1:
                cout << "(" << arg1 << ")" << " + " << "(" << arg2 << ")" << " = " << add(arg1, arg2) << endl;
                break;
            case 2:
                cout << "(" << arg1 << ")" << " - " << "(" << arg2 << ")" << " = " << sub(arg1, arg2) << endl;
                break;
            case 3:
                cout << "(" << arg1 << ")" << " * " << "(" << arg2 << ")" << " = " << mult(arg1, arg2) << endl;
                break;
            case 4:
                if (arg2 == 0) {
                    cout << "Error: division by 0" << endl;
                } else cout << "(" << arg1 << ")" << " / " << "(" << arg2 << ")" << " = " << div(arg1, arg2) << endl;
                break;
            default:
                cout << "Good bye!" << endl;
                break;
        }
    cout << endl;
    return 0;
}

// Choices
float add(double a, double b) {
    return a + b;
}
float sub(double a, double b) {
    return a - b;
}
float mult(double a, double b) {
    return a * b;
}
float div(double a, double b) {
    return a / b;
}