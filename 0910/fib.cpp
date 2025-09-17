
#include <iostream>
using namespace std;

int main() {
    double a = 1;
    double b = 1;
    double c = 1;
    for (int n = 0; n < 1500; n++) {
        c = a + b;
        a = b;
        b = c;
        cout << a << " ";
    }
    return 0;
}
