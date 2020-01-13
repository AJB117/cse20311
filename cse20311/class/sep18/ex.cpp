#include <iostream>
#include <cmath>
// #define PI 3.14159       Macro; antiquated
using namespace std;
float halfof(double);

int main() {
    const double pi = 3.14159;  // Const
    cout << pi << endl;
    cout << M_PI << endl;   // M_PI only in cmath; predefined macro to many digits
    return 0;
}

float halfof(double a) {
    return a/2;
}