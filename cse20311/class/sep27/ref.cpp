#include <iostream>
using namespace std;
int func1(int);         // passing by value
int func2(int &);       // passing by reference

int main() {
    int n = 5;
    cout << n << endl;
    func1(n);           // 5
    cout << n << endl;
    func2(n);
    cout << n << endl;  // 8

    return 0;
}

int func1(int n) {
    n = 8;
}

int func2(int &a) {
    a = 8;
}