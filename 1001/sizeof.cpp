
#include <iostream>
using namespace std;

int main() {
    char c1, c2, c3, c4;
    short s1, s2, s3, s4;
    int i1, i2, i3, i4;
    long l1, l2, l3, l4;
    long long L1, L2, L3, L4;
    float f1, f2, f3, f4;
    double d1, d2, d3, d4;
    long double D1, D2, D3, D4;
    
    cout << "sizeof(char): " << sizeof(c1) << endl;
    cout << &c1 - &c2 << " " << &c2 - &c3 << " " << &c3 - &c4 << endl;

    cout << "sizeof(short): " << sizeof(s1) << endl;
    cout << &s1 - &s2 << " " << &s2 - &s3 << " " << &s3 - &s4 << endl;

    cout << "sizeof(int): " << sizeof(i1) << endl;
    cout << &i1 - &i2 << " " << &i2 - &i3 << " " << &i3 - &i4 << endl;

    cout << "sizeof(long): " << sizeof(l1) << endl;
    cout << &l1 - &l2 << " " << &l2 - &l3 << " " << &l3 - &l4 << endl;

    cout << "sizeof(long long): " << sizeof(L1) << endl;
    cout << &L1 - &L2 << " " << &L2 - &L3 << " " << &L3 - &L4 << endl;

    cout << "sizeof(float): " << sizeof(f1) << endl;
    cout << &f1 - &f2 << " " << &f2 - &f3 << " " << &f3 - &f4 << endl;

    cout << "sizeof(double): " << sizeof(d1) << endl;
    cout << &d1 - &d2 << " " << &d2 - &d3 << " " << &d3 - &d4 << endl;

    cout << "sizeof(long double): " << sizeof(D1) << endl;
    cout << &D1 - &D2 << " " << &D2 - &D3 << " " << &D3 - &D4 << endl;

    cout << (int*)&D1 - (int*)&s2;

    return 0;
}

