
#include <iostream>
using namespace std;

int main() {
    char c1; short s1; int i1; long l1; long long L1; float f1; double d1; long double D1;
    char c2; short s2; int i2; long l2; long long L2; float f2; double d2; long double D2;
    char c3; short s3; int i3; long l3; long long L3; float f3; double d3; long double D3;
    char c4; short s4; int i4; long l4; long long L4; float f4; double d4; long double D4;
    
    cout << "The first copy" << endl;
    cout << (void*)&c1 << "\n" << &s1 << "\n" << &i1 << "\n" << &l1 << "\n" << &L1 << "\n" << &f1 << "\n" << &d1 << "\n" << &D1 << endl;
    cout << endl;

    cout << "The second copy" << endl;
    cout << (void*)&c2 << "\n" << &s2 << "\n" << &i2 << "\n" << &l2 << "\n" << &L2 << "\n" << &f2 << "\n" << &d2 << "\n" << &D2 << endl;
    cout << endl;

    cout << "The third copy" << endl;
    cout << (void*)&c3 << "\n" << &s3 << "\n" << &i3 << "\n" << &l3 << "\n" << &L3 << "\n" << &f3 << "\n" << &d3 << "\n" << &D3 << endl;
    cout << endl;

    cout << "The fourth copy" << endl;
    cout << (void*)&c4 << "\n" << &s4 << "\n" << &i4 << "\n" << &l4 << "\n" << &L4 << "\n" << &f4 << "\n" << &d4 << "\n" << &D4 << endl;
    cout << endl;

    return 0;
}

