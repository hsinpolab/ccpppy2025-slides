
#include <iostream>
using namespace std;

int main() {
    int A[100] = {};
    
    cout << A << endl;
    cout << &A[0] << endl;
    cout << &false[A] << endl;
    cout << endl;

    cout << A + 1 << endl;
    cout << &A[1] << endl;
    cout << &true[A] << endl;
    cout << endl;

    cout << A + 2 << endl;
    cout << &A[2] << endl;
    cout << &2[A] << endl;
    cout << endl;
    
    cout << A + 3 << endl;
    cout << &A[3] << endl;
    cout << &3[A] << endl;
    cout << endl;
    
    cout << A + 4 << endl;
    cout << &A[4] << endl;
    cout << &4[A] << endl;
    cout << endl;

    return 0;
}

