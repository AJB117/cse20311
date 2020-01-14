#include <iostream>
#include <string>
using namespace std;
int sum(int, int);

int main(int argc, char *argv[]) {
    int a, b;
    if (argc == 1) {
        cout << "Please enter two integers: " << endl;
        cin >> a >> b;
        cout << "Sum: " << sum(a, b) << endl;
    }
    else if (argc == 3)
        cout << "Sum: " << sum(stoi(argv[1]), stoi(argv[2])) << endl;
    else {
        cout << "Error: either enter no arguments or enter two numbers" << endl;
        return 1;
    }
    return 0;
}

int sum(int a, int b) {
    return a+b;
}