#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main() {
    char s1[] = "hi there";
    cout << s1 << " - " << strlen(s1) << endl;

    string s2 = "how are you";
    cout << s2 << " - " << s2.length() << endl;

    string s3("cs & cpeg");
    // string s3{"cs & cpeg"};
    // string s3 = {"cs & cpeg"};
    
    cout << s3 << " - " << s3.length() << endl;
    
    string s;
    cout << "enter: ";
    // cin >> s;
    cout << "***" << s << "***" << endl;            // Spaces aren't read into cin since space is a delimiter
                                                    // for natural input; any other delimeter acts as 1 (e.g. two commas not allowed)
    cout << "enter another string: ";
    getline(cin, s);                                // getline() uses \n as a delimeter instead; using the function not the method since it's a c++ str
    cout << "***" << s <<"***" << endl;             // won't work unless you ignore() or not do a cin() beforehand since cin() sends a \n                               


    // C++      standard    
    // input:   cin         ifstream
    // output:  cout        ofstream
    // from:    iostream    fstream
    return 0;
}