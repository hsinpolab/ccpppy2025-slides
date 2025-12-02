
#include <iostream>
using namespace std;

int main() {
    int a = 1, b = 3, c = 2;
    int *p = &a, *q = &b, *r = &c;
    int **x = &p, **y = &q, **z = &r;
    cout << **x << **y << **z << endl;
    swap(x, y);
    cout << **x << **y << **z << endl;
    swap(a, c); swap(q, r);
    cout << **x << **y << **z << endl;
    swap(*x, *z);
    cout << **x << **y << **y << endl;
    swap(*p, *q); swap(**y, **z);
    cout << **x << **y << **z << endl;
    cout << 1*a**p***x << endl;
}

