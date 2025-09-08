
#include <iostream>
using namespace std;

int main() {
    cout << "  |  ";
    for (int j = 1; j < 10; j++) { 
        cout << j << "  ";
    }
    cout << endl;
    cout << "--+-";
    for (int j = 1; j < 10; j++) { 
        cout << "---";
    }
    cout << endl;
    for (int i = 1; i < 10; i++) {
        cout << i << " | ";
        for (int j = 1; j < 10; j++) {
            int a = i * j / 10;
            int b = i * j % 10;
            cout << a << b << " ";
        }
        cout << endl;
    }
    return 0;
}
