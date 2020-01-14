#include <iostream>
using namespace std;

int main() {
    int inputs[5];
    for (int i = 0; i < 5; i++) {
        cin >> inputs[i];
    }
    for (int j = 4; j >= 0; j--) {
        cout << inputs[j] << " ";
    }
    cout << endl;
    return 0;
}