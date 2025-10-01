
#include <iostream>
using namespace std;

int main() {
    int A[10][20][30] = {};

    cout << &A[1][2][3] << endl;
    cout << &1[A][2][3] << endl;
    cout << &2[A[1]][3] << endl;
    cout << &2[1[A]][3] << endl;
    cout << &3[A[1][2]] << endl;
    cout << &3[1[A][2]] << endl;
    cout << &3[2[A[1]]] << endl;
    cout << &3[2[1[A]]] << endl;
    
    return 0;
}

