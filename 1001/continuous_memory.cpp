
#include <iostream>
using namespace std;

int main() {
    int a = 12;
    int b = 14;
    int c = 16;
    int d = 18;

    int *ptr;

    ptr = &a;
    cout << ptr << " is " << *ptr << endl;
    ptr = &b;
    cout << ptr << " is " << *ptr << endl;
    ptr = &c;
    cout << ptr << " is " << *ptr << endl;
    ptr = &d;
    cout << ptr << " is " << *ptr << endl;
    return 0;
}

