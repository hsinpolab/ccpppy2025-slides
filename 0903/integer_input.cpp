
#include <iostream>
using namespace std;

int main() {
    int a = 1; // a is currently 1
    cout << "In the beginning, a is " << a << endl;
    
    cin >> a; // read a from keyboard, so a is not 1 anymore
    cout << "After cin, a is now " << a << endl;

    a /= 10;
    cout << "After division, a is now " << a << endl;

    int b = 2; // b is currently 2
    cout << "In the beginning, b is " << b << endl;

    cin >> b;
    cout << "After cin, b is now " << b << endl;

    b = a + b;
    cout << "After addition, b is now " << b << endl;

    return 0;
}
