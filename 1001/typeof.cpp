
#include <iostream>
#include <typeinfo>
using namespace std;

float func(int x, int y, int z, int w) {
    cout << x << y << z;
    return 3.14;
}

int main() {
    int n = 42;
    int *p;
    double d = 3.14;
    float fs[10];
    char css[20][30][40][50];

    cout << "typeid(n).name(): " << typeid(n).name() << endl;
    cout << "typeid(p).name(): " << typeid(p).name() << endl;
    cout << "typeid(d).name(): " << typeid(d).name() << endl;
    cout << "typeid(fs).name(): " << typeid(fs).name() << endl;
    cout << "typeid(fs + 1).name(): " << typeid(fs + 1).name() << endl;
    cout << "typeid(css).name(): " << typeid(css).name() << endl;
    cout << "typeid(func).name(): " << typeid(func).name() << endl;
    cout << endl;

    return 0;
}

