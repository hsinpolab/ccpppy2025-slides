
#include <iostream>
using namespace std;

float factorial(float k) {
    if (k <= 1) return 1;
    return k * factorial(k - 1);
}

int factorial(int k) {
    if (k <= 1) return 1;
    return k * factorial(k - 1);
}

int main () {
    int m;
    cin >> m;
    cout << factorial(m) << endl;
    float n;
    cin >> n;
    cout << factorial(n) << endl;
}

