
#include <iostream>
#include <typeinfo>
using namespace std;

float func(char x, int y, long long z) {
    cout << x << y << z
    return 3.14;
}

int main() {
    int n = 42;
    int *p;
    double d = 3.14;
    float fs[10];
    char css[20][30];

    std::cout << "typeid(n).name(): " << typeid(n).name() << endl;
    std::cout << "typeid(p).name(): " << typeid(p).name() << endl;
    std::cout << "typeid(d).name(): " << typeid(d).name() << endl;
    std::cout << "typeid(fs).name(): " << typeid(fs).name() << endl;
    std::cout << "typeid(fs + 1).name(): " << typeid(fs + 1).name() << endl;
    std::cout << "typeid(css).name(): " << typeid(css).name() << endl;
    std::cout << "typeid(func).name(): " << typeid(func).name() << endl;
    std::cout << endl;

    return 0;
}

