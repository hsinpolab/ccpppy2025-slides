
#include <iostream>
#include <cassert>
using namespace std;

int main() {
    int n = 123456789;
    float L = 0;
    float R = 20000;
    assert(L * L <= n);
    assert(R * R >= n);
    for (int it = 0; it < 100; it++) {
        float M = (L + R) / 2;
        if (M * M >= n) {
            R = M;
        }
        if (M * M <= n) {
            L = M;
        }
    }
    float ans = (L + R) / 2;
    cout << "Our best number ans^2 = n is " << ans << endl;
    cout << "To double check, notice that answer^2 = " << ans * ans << endl;
    return 0;
}
