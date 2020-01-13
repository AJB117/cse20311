#include <iostream>
using namespace std;

int sumofsquares(int, int);
void greet();
int main() {
    int a, b;
    a = 12;
    b = 27;

    int c = sumofsquares(a, b);
    cout << "c: " << c << endl;

    greet();
    return 0;
}

int sumofsquares(int a, int b) {
    return (a*a) + (b* b);
}

void greet() {
    cout << "Hi!" << endl;
}