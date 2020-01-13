#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    // Problem 1
    cout << "Problem 1: " << endl;
    int x;
    x = 9 / 4 + 17 / 6 - (12 % 8) + (8 - 3 * 4) + (3 / 4 * 4);

    cout << "answer: " << x << endl;

    cout << "-------------" << endl;

    // Problem 2
    cout << "Problem 2: " << endl;
    // int a, b, c;
    // a = 5;
    // c = 3;
    // b = 4 + a--;
    // c = b++ + --a;
    // cout << "answer: " << endl;
    // cout << "a: " << a << endl;
    // cout << "b: " << b << endl;
    // cout << "c: " << c << endl;

    cout << "-------------" << endl;

    // Problem 3
    cout << "Problem 3: " << endl;
    int a, b, num = 5, s = 0;
    for (a = 1; a < num; a++) {
        for (b = a; b > 0; b--) {
            if (a != b) {
                s = s + a * b;
                cout << s << " ";
            }
        }
    }

    cout << endl;
    int g = __gcd(6, 20);
    cout << g << endl;
    return 0;
}