
#include <iostream>
#include <cmath>
using namespace std;

int main () {
    cout << cos(3.1415926 * 0) << endl; // should be close to 1
    cout << cos(3.1415926 / 6) << endl; // should be close to sqrt(3)/2
    cout << cos(3.1415926 / 3) << endl; // should be close to 1/2
    cout << cos(3.1415926 / 2) << endl; // should be close to 0
    cout << cos(3.1415926 / 1) << endl; // should be close to -1
}

