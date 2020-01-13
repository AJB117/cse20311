#include <iostream>
#include <iomanip>
using namespace std;
void flip(int[], int);

int main() {
    int i = 1;
    while(i <=  10) {
        cout << i<< endl;
        if (i==10) break;
        i++;
        if (i==4) continue;
    }

    cout << (1/4);              // 0
    cout << ((float)1/4);       // 0.25

    cout << endl << "---------" << endl;

    int arr[7] = {7,5,9,2,6,4, 9};
    flip(arr, 7);
    for (int i = 0; i < 7; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "----------" << endl;

    const char star = '*';
    const char space = ' ';
    int n;
    cout << "Enter n: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        if (i == 0 || i == n-1) {
            for (int j = 0; j < n; j++) {
                cout << star;
            }
            cout << endl;
        }
        else {
            for (int k = 0; k < n; k++) {
                if (k == 0 || k == n-1) {
                    cout << star;
                }
                else cout << space;
            }
            cout << endl;
        }
    }
    for (int w = 0; w < 10; w++)
    for (int t = 10; t < 20; t++)
    cout << w << " ";

}

void flip(int arr[], int size) {
    int ref[size];
    for (int i = 0; i < size; i++) {
        ref[i] = arr[i];
    }
    for (int j = 0; j < size; j++) {
        arr[j] = ref[size-1-j];
    }
}