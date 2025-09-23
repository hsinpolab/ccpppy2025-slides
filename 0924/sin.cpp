
#include <iostream>
using namespace std;

float sin(float x) {
    // Taylor series for sin(x) = x - x^3/3! + x^5/5! - ...
    float term = x; // First term is x
    float result = term;
    for (int i = 1; i < 10; ++i) { // 10 terms for approximation
        term = -term * x * x / ((2 * i) * (2 * i + 1));
        result += term;
    }
    return result;
}

int main () {

    cout << sin(3.1415926 / 6) << endl; // should be close to 1/2
    cout << sin(3.1415926 / 3) << endl; // should be close to sqrt(3)/2
    cout << sin(3.1415926 / 2) << endl; // should be close to 1
    cout << sin(3.1415926 / 1) << endl; // should be close to 0
}

