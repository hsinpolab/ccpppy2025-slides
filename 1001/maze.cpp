
#include <iostream>
using namespace std;

int main() {
    int a1, a2, a3;
    a1 = 11;
    a2 = 22;
    a3 = 33;
    int *b1, *b2, *b3;
    b1 = &a1;
    b2 = &a2;
    b3 = &a3;
    int **c1, **c2, **c3;
    c1 = &b1;
    c2 = &b2;
    c3 = &b3;
    cout << **c1 << " " << **c2 << " " << **c3 << endl;
    swap(a1, a2);
    cout << **c1 << " " << **c2 << " " << **c3 << endl;
    swap(b2, b3);
    cout << **c1 << " " << **c2 << " " << **c3 << endl;
    swap(c1, c3);
    cout << **c1 << " " << **c2 << " " << **c3 << endl;
    swap(*b1, *b2);
    cout << **c1 << " " << **c2 << " " << **c3 << endl;
    swap(*c2, *c3);
    cout << **c1 << " " << **c2 << " " << **c3 << endl;
    swap(**c1, **c3);
    cout << **c1 << " " << **c2 << " " << **c3 << endl;
    return 0;
}

