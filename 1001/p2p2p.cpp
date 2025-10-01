
#include <iostream>
using namespace std;

int main() {
    int a;
    int *b;
    int **c;
    int ***d;
    int ****e;

    a = 42;
    b = &a;
    c = &b;
    d = &c;
    e = &d;

    cout << a << endl;
    cout << *b << " " << b << endl;
    cout << **c << " " << *c << " " << c << endl;
    cout << ***d << " " << **d << " " << *d << " " << d << endl;
    cout << ****e << " " << ***e << " " << **e << " " << *e << " " << e << endl;

    return 0;
}

