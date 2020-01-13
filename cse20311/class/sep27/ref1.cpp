#include <iostream>
using namespace std;
void func(int &, int &, int);
void compute(int &, int &);

int main() {
    int a, b, c;
    a = 10;
    b = 11;
    c = 12;
    func(a, b, c);
    cout << a << " " << b << " " << c << endl;  // a and b are passed by ref; c is passed by value
    compute(a, b);
    cout << a << endl;
    return 0;
}

void func(int &a, int &b, int c) {
    a = 13;
    b = 14;
    c = 15;
}

void compute(int &a, int &b) {
    a *= b;
}