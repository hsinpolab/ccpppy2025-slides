
#include <iostream>
using namespace std;

int main() {
    double x = 0;
    double a = 1/1000000.;
    for (int i = 0; i < 1000000; i++) {
        x += a; // This is the same as x = x + a;
    }
    cout << x << endl;
    return 0;
}
