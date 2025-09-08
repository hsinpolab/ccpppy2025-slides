
#include <iostream>
#include <cassert>
using namespace std;

int main() {
    int n = 123456789;
    int L = 0;
    int R = 20000;
    int ans = 0;
    assert(L * L < n);
    assert(R * R >= n);
    for (int it = 0; it < 100; it++) {
        int M = (L + R) / 2;
        if (M * M >= n) {
            R = M;
        }
        if (M * M < n) {
            L = M;
        }
        if (L + 1 == R) {
            // L is bad and R is good
            // and there are no other number in between
            ans = R;
            break;
        }
    }
    cout << "The least number such that ans^2 >= n is " << ans << endl;
    cout << "To double check, notice that (ans - 1)^2 = " << (ans - 1) * (ans - 1)
    << ", n = " << n << ", and ans^2 = " << ans * ans << endl;
    return 0;
}
