#include <iostream>
using namespace std;

int main() {
    int a[10] = {};                     // outputs 0s
    for (int i = 0; i < 10; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}