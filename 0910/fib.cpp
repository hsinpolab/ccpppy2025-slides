
#include <iostream>
using namespace std;

int main() {
    float a = 1;
    float b = 1;
    float c = 1;
    for (int n = 0; n < 200; n++) {
        c = a + b;
        a = b;
        b = c;
        cout << a << " ";
    }
    return 0;
}
