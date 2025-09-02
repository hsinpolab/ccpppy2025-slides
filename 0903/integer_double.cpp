
#include <iostream>
using namespace std;

int main() {
    int a = 1; // a is currently 1
    cout << a << endl;

    a = a + a; // a is currently 2
    cout << a << endl;

    a = a * 2; // a is currently 4
    cout << a << endl;
    
    a = 2 * a; // a is currently 8
    cout << a << endl;

    a += a; // a is currently 16
    cout << a << endl;

    a *= 2; // a is currently 32
    cout << a << endl;
    return 0;
}
