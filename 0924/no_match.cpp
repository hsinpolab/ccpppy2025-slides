
#include <iostream>
using namespace std;

int factorial(int k) {
    if (k == 0) return 1;
    return k * factorial(k - 1);
}

int main () {
    string n;
    cin >> n;
    cout << factorial(n) << endl;
}

